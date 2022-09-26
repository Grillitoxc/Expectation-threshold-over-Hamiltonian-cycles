#include "Graph.h"

#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
#define WHITE "\033[1;29m"

int main() {
    Graph graph(15);
    graph.createGraph(0.5);
    cout << endl;
    graph.print();
    vector<int> adjacentNodes;
    adjacentNodes = graph.getAdjacentNodes(0);
    if (adjacentNodes.size() != 0){
        cout << endl << YELLOW << "Nodos adjacentes de 0: " << RESET;
        for (int i = 0; i < adjacentNodes.size(); i++) {
            cout << WHITE << adjacentNodes[i] << " " << RESET;
        }
    } else
        cout << endl << YELLOW << "No hay nodos adjacentes a 0" << RESET;

    graph.doesEdgeExist(0, 1);
    cout << endl << YELLOW << "Número de nodos totales: " << RESET << WHITE << graph.getNumberOfNodes() << RESET 
        <<endl << endl;
    graph.saveGraph("generated_graph.txt");
    return 0;
}