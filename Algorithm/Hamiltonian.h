#ifndef Hamiltonian_h
#define Hamiltonian_h

#include <thread>
#include <stdlib.h>
#include <mutex>
#include <atomic>
#include "Graph.h"
using namespace std;

/*
    * Hamiltonian class:
    * This class is used to solve the Hamiltonian cycle problem
    * using a paralel backtracking algorithm. It uses a graph
    * as input and it returns a boolean value indicating if the
    * graph has a Hamiltonian cycle or not.
*/
class Hamiltonian {
    private:
        mutex locker; // Mutex to lock the critical section of the algorithm.
        bool solutionFound; // Flag to indicate if a solution was found.
        vector<int> solution; 
        atomic<int> threadCounter; // Atomic counter to count the number of threads that have finished.
        vector<vector<int>> solutionsForEachThread; // Vector of vectors to store the solutions for each thread.
    public:
        // Constructor
        Hamiltonian();

        // Getters
        vector<int> getHamiltonCycle();

        // Other methods
        bool hasSolution() const;
        void saveSolution(string fileName);
        void hamiltonianSolve(Graph graph);
        void nodeSearch(Graph graph, int currentNode, vector<int>* possibleSolution);
};

#endif /* Hamiltonian_h */