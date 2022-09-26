#include "Graph.h"

/*
    * Method: Constructor->Graph
    * Description: This method is used to create a graph with the given number of vertices.
    * Parameters:
    *  - nodes: The number of vertices in the graph.
    * Return:
    *  - Vone.
*/
Graph::Graph(int nodes){
    numberOfNodes = nodes;
    for (int i = 0; i < numberOfNodes; i++)
        graphContainer.emplace_back();
}

/*
    * Method: Constructor->createGraph
    * Description: This method is used to create a random graph with the given probability of edges.
    * Parameters:
    *  - probability: The probability of matching a pair of nodes.
    * Return:
    *  - Void.
*/
void Graph::createGraph(double probability) {
    if (graphContainer.size() == 0) {
        for (int i = 0; i < numberOfNodes; i++)
            graphContainer.emplace_back();
    }
    srand(time(NULL));
    for (int i = 0; i < numberOfNodes; i++) {
        for (int j = i+1; j < numberOfNodes; j++) {
            if (double(rand())/RAND_MAX < probability)
                addEdge(i, j);
        }
    }
}

/*
    * Method: Destructor->cleanContainer
    * Description: This method is used to clean the graph container by clearing it.
    * Parameters:
    *  - None.
    * Return:
    *  - Void.
*/
void Graph::cleanContainer(){
    graphContainer.clear();
}

/*
    * Method: Getter->getNumberOfNodes
    * Description: This method is used to get the number of nodes in the graph.
    * Parameters:
    *  - None.
    * Return:
    *  - The number of vertices in the graph.
*/
int Graph::getNumberOfNodes() {
    return numberOfNodes;
}

/*
    * Method: Getter->getAdjacentNodes
    * Description: This method is used to get the adjacent nodes of a given node.
    * Parameters:
    *  - node: The node to get the adjacent nodes of.
    * Return:
    *  - The vector of adjacent nodes of the given node.
*/
vector<int> Graph::getAdjacentNodes(int node) {
    return graphContainer[node];
}

/*
    * Method: Setter->addEdge
    * Description: This method is used to add an edge to the graph between two given nodes.
    * Parameters:
    *  - node: The node to add the edge to.
    *  - otherNode: The other node to add the edge to.
    * Return:
    *  - Void.
*/
void Graph::addEdge(int node, int otherNode) {
    graphContainer[node].push_back(otherNode);
    graphContainer[otherNode].push_back(node);
}

/*
    * Method: Other->doesEdgeExist
    * Description: This method is used to check if an edge exists between two given nodes.
    * Parameters:
    *  - firstNode: The first node to check the edge between.
    *  - secondNode: The second node to check the edge between.
    * Return:
    *  - True if an edge exists between the two nodes, false otherwise.
*/
bool Graph::doesEdgeExist(int firstNode, int secondNode) {
    return find(graphContainer[firstNode].begin(), graphContainer[firstNode].end(), secondNode)
                != graphContainer[firstNode].end();
}

/*
    * Method: Other->saveGraph
    * Description: This method is used to save the graph to a file.
    * Parameters:
    *  - fileName: The name of the file to save the graph to.
    * Return:
    *  - Void.
*/
void Graph::saveGraph(string fileName) {
    ofstream file;
    file.open(fileName);
    string graphAsText;
    for (int nodeIndex = 0; nodeIndex < numberOfNodes; nodeIndex++) {
        for (int neighbourIndex = 0; neighbourIndex < graphContainer[nodeIndex].size(); neighbourIndex++)
            graphAsText += to_string(nodeIndex ) + " " + to_string(graphContainer[nodeIndex][neighbourIndex]) + "\n";
    }
    file << graphAsText;
    file.close();
}

/*
    * Method: Other->print
    * Description: This method is used to print the graph to the console.
    * Parameters:
    *  - None.
    * Return:
    *  - Void.
*/
void Graph::print() {
    cout << "\033[1;7;31mGraph container:\033[0m" << endl;
    for (int nodeIndex = 0; nodeIndex < graphContainer.size(); nodeIndex++) {
        cout << nodeIndex << ": ";
        for (int neighbourIndex = 0; neighbourIndex < graphContainer[nodeIndex].size(); neighbourIndex++)
            cout << graphContainer[nodeIndex][neighbourIndex] << " ";
        cout << endl;
    }
}