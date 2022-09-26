#ifndef Graph_h
#define Graph_h

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    * Graph class:
    * This class is used to create a random graph with the given
    * number of vertices and the given probability of edges.
    * The graph is represented by a vector of vectors and the
    * nodes are represented by the index of the main vector.
*/
class Graph {
    private:
        int numberOfNodes;
        vector<vector<int>> graphContainer;
    public:
        // Constructor
        Graph(int nodes);
        void createGraph(double probability);

        // Destructor
        void cleanContainer();

        // Getters
        int getNumberOfNodes();
        vector<int> getAdjacentNodes(int node);

        // Setters
        void addEdge(int node, int otherNode);
        
        // Other methods
        bool doesEdgeExist(int firstNode, int secondNode);
        void saveGraph(string fileName);
        void print();
};

#endif /* Graph_h */