#include <time.h>
#include "Hamiltonian.h"

#define RED_BACKGROUND  "\033[1;7;31m"
#define RESET "\033[0m"

struct timespec start, finish;

int main() {
    /*
    Asegurarse de que el número de procesadores asignados a la máquina sea igual o mayor
    al número de nodos del grafo. Esto debido a que el algoritmo de búsqueda de ciclos
    asigna un número de hilos igual al número de procesadores disponibles.
    */
    double time;
    Graph graph(300);
    graph.createGraph(0.2);
    Hamiltonian solver;
    clock_gettime(CLOCK_MONOTONIC, &start);
    solver.hamiltonianSolve(graph);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    time = (double)(finish.tv_sec - start.tv_sec) + (double)(finish.tv_nsec - start.tv_nsec) / 1000000000;
    if (solver.hasSolution()) {
        vector<int> solution = solver.getHamiltonCycle();
        cout << endl << RED_BACKGROUND << "Solución:" << RESET << endl;
        for (int nodeIndex = 0; nodeIndex < solution.size(); nodeIndex++) {
            cout << solution[nodeIndex] << " ";
        }
    } else
        cout << RED_BACKGROUND << "No se encontró un camino hamiltoniano." << RESET << endl << endl;
    cout << endl << RED_BACKGROUND << "Tiempo de ejecución:" << RESET << endl << time << " segundos." << endl;
    cout << endl << endl;
    return 0;
}