#include <math.h>
#include <time.h>
#include <unistd.h>
#include "Hamiltonian.h"

#define RED_BACKGROUND  "\033[1;7;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

struct timespec start, finish;

int main(){
    int N = 15;
    int max_iterations = 1000;
    double limit_P0 = log(N)/N;
    clock_t t0, t1;
    unsigned int microsecond = 1000000;
    double tprom1, time1, time2;
    vector<double> probabilities;
    int solutions[30];

    cout << endl << RED_BACKGROUND << "Creando nuevo grafo: 0" << RESET << endl;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for (int k = 0; k < max_iterations; k++) {
        Graph graph(N);
        // Clean the solutions vector
        for (int i = 0; i < 30; i++)
            solutions[i] = 0;

        // Reset probability
        double probability = 0.03;
        
        for (int i = 0; i < 30; i++) {
            graph.createGraph(probability);        
            Hamiltonian solver;
            t0 = clock();
            solver.hamiltonianSolve(graph);
            t1 = clock();
            cout << "Iniciando con probabilidad: " << probability << endl;
            if (solver.hasSolution()) {
                solutions[i] = 1;
                if (k != max_iterations-1)
                    cout << RED_BACKGROUND << "Creando nuevo grafo: " << k+1 << " " << RESET << endl;
                    usleep(microsecond/2); // Sleep for 0.5 seconds
                break;
            }
            probability += 0.03;
            graph.cleanContainer();
        }
        time1 = (double)(t1-t0) / CLOCKS_PER_SEC;
        tprom1 += time1;
        // Store the probability in the vector
        for (int j = 0; j < 30; j++) {
            if (solutions[j] == 1)
                probabilities.push_back(probability);
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    time2 = (double)(finish.tv_sec - start.tv_sec) + (double)(finish.tv_nsec - start.tv_nsec) / 1000000000;

    // Calculate the mean of the vector
    double mean = 0;
    for (int i = 0; i < probabilities.size(); i++)
        mean += probabilities[i];

    mean /= probabilities.size();
    int threads = thread::hardware_concurrency();

    // Write a file with the results of probilities vector
    ofstream file;
    file.open("probabilitiesN15_New.txt");
    for (int i = 0; i < probabilities.size(); i++)
        file << probabilities[i] << endl;

    cout << endl << YELLOW << "Tiempo promedio por cada solución:   " << RESET << tprom1/30 << endl;
    cout << YELLOW << "Tiempo total de ejecución:           " << RESET << time2 << endl;
    cout << YELLOW << "La media obtenida (50 iteraciones):  " << RESET << mean << endl;
    cout << YELLOW << "Conjetura Kahn-Kalai (log(n)/n):     " << RESET << limit_P0 << endl;
    cout << YELLOW << "Hilos del procesador utilizados:     " << RESET << threads << endl << endl;
}