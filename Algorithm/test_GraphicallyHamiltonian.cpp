#include "Hamiltonian.h"

#define RED_BACKGROUND  "\033[1;7;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

struct timespec start, finish;

int main() {
    double time;
    Graph graph(15);
    graph.createGraph(0.5);
    cout << endl;
    graph.print();
    graph.saveGraph("graphically_hamiltonian.txt");
    Hamiltonian solver;
    clock_gettime(CLOCK_MONOTONIC, &start);
    solver.hamiltonianSolve(graph);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    if (solver.hasSolution()) {
        vector<int> solution = solver.getHamiltonCycle();
        cout << endl << RED_BACKGROUND << "Solución:" << RESET << endl;
        for (int nodeIndex = 0; nodeIndex < solution.size(); nodeIndex++)
            cout << solution[nodeIndex] << " ";
    } else
        cout << RED_BACKGROUND << "No se encontró un camino hamiltoniano." << RESET << endl;
    cout << endl << endl;
    time = (double)(finish.tv_sec - start.tv_sec) + (double)(finish.tv_nsec - start.tv_nsec) / 1000000000;
    cout << RED_BACKGROUND << "Tiempo de ejecución: " << time << " segundos." << RESET << endl;
    solver.saveSolution("graphically_hamiltonian.txt");
    graph.saveGraph("graphically_hamiltonian_graph.txt");
    return 0;
}