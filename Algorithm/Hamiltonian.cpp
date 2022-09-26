#include "Hamiltonian.h"

/*
    * Method: Constructor->Hamiltonian
    * Description: This method is used to create a new instance of the Hamiltonian class.
    * Parameters:
    *  - None.
    * Return:
    *  - Void.
*/
Hamiltonian::Hamiltonian() {
    solutionFound = false;
    threadCounter.store(0);
}

/*
    * Method: Getter->getHamiltonCycle
    * Description: This method is used to get the solution of the Hamiltonian problem as a vector of nodes.
    * Parameters:
    *  - None.
    * Return:
    *  - The solution of the Hamiltonian problem.
*/
vector<int> Hamiltonian::getHamiltonCycle() {
    return solution;
}

/*
    * Method: Other->hasSolution
    * Description: This method is used to check if a solution was found.
    * Parameters:
    *  - None.
    * Return:
    *  - True if a solution was found, false otherwise.
*/
bool Hamiltonian::hasSolution() const {
    return solutionFound;
}

/*
    * Method: Other->saveSolution
    * Description: This method is used to save the solution of the Hamiltonian problem to a file.
    * Parameters:
    *  - fileName: The name of the file to save the solution to.
    * Return:
    *  - Void.
*/
void Hamiltonian::saveSolution(string fileName) {
    ofstream file;
    file.open(fileName);
    for (int nodeIndex = 0; nodeIndex < solution.size(); nodeIndex++) {
        file << solution[nodeIndex] << endl;
    }
    file.close();
}

/*
    * Method: Other->hamiltonianSolve
    * Description: This method is used to solve the Hamiltonian problem. It is called by the main method.
    * This is a simple backtracking algorithm that is implemented using threads to solve the problem.
    * The idea is to start from each node and try to find a Hamiltonian cycle by iterating through all the possible
    * nodes that can be added to the current solution. If a solution is found, it is saved and the algorithm stops and
    * kills all the threads. If no solution is found, the algorithm kills all the threads and returns.
    * One thing to note is that the algorithm is not guaranteed to find a solution. It is possible that the algorithm
    * will not find a solution if the graph is not connected (having multiple subgraphs) or if the graph is not
    * Hamiltonian (having a cycle).
    * The algorithm is also structured in a way that it can be used in a multithreaded environment (have critical
    * sections protected by mutexes).
    * Parameters:
    *  - graph: The graph to solve the problem on.
    * Return:
    *  - Void.
*/
void Hamiltonian::hamiltonianSolve(Graph graph) {
    vector<thread> threads;
    int numberOfNodes = graph.getNumberOfNodes();
    int nodesPerThread = (int)(!numberOfNodes / thread::hardware_concurrency() ? 1 :numberOfNodes /
                                thread::hardware_concurrency());

    for (int threadIndex = 0; threadIndex < thread::hardware_concurrency(); threadIndex++)
        solutionsForEachThread.emplace_back();

    for (int nodeIndex = 0; nodeIndex < numberOfNodes; nodeIndex += nodesPerThread) {
        threads.emplace_back([=]() mutable {
            int threadIndex = threadCounter.fetch_add(1);
            for (int chunkNode = nodeIndex; chunkNode < min(nodeIndex + nodesPerThread, numberOfNodes); chunkNode++) {
                solutionsForEachThread[threadIndex].clear();
                solutionsForEachThread[threadIndex].push_back(chunkNode);
                nodeSearch(graph, chunkNode, &(solutionsForEachThread[threadIndex]));
            }
        });
    }
    for (int threadIndex = 0; threadIndex < threads.size(); threadIndex++)
        threads[threadIndex].join();
}

/*
    * Method: Other->nodeSearch
    * Description: This method is used to try to find a solution from a given node. This method is called recursively.
    * The main idea is do the backtracking using threads to speed up the process.
    * Parameters:
    *  - Graph graph: The graph to use.
    *  - int currentNode: The node to start from.
    *  - vector<int>* possibleSolution: The solution to try.
    * Return:
    *  - Void.
*/
void Hamiltonian::nodeSearch(Graph graph, int currentNode, vector<int>* possibleSolution) {
    if (possibleSolution->size() == graph.getNumberOfNodes()) {
        int firstNodeInPath = (*possibleSolution)[0];
        int lastNodeInPath = (*possibleSolution)[possibleSolution->size() - 1];

        if (graph.doesEdgeExist(lastNodeInPath, firstNodeInPath)) {
            /* Sección crítica */
            locker.lock();
            if (!solutionFound) {
                solutionFound = true;
                possibleSolution->push_back(firstNodeInPath);
                solution = *possibleSolution;
            }
            locker.unlock();
            /* Fin sección crítica */
        }
        return;
    }
    for (int nodeIndex = 0; nodeIndex < graph.getNumberOfNodes() && !solutionFound; nodeIndex++) {
        if (!count(possibleSolution->begin(), possibleSolution->end(), nodeIndex) && graph.doesEdgeExist(currentNode,
            nodeIndex)) {
            possibleSolution->push_back(nodeIndex);
            nodeSearch(graph, nodeIndex, possibleSolution);
            if (solutionFound)
                return;
            possibleSolution->pop_back();
        }
    }
}