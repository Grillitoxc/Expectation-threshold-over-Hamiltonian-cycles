FLAGS = -g
FLAGS = -O2

# Para correr los test correctamente:
# 1) Si se desea aplicar el test del grafo, se debe correr tanto:
#		test_Graph y GraphVerifier.py [DESCOMENTAR AMBOS]
#
# 2) Si se desea aplicar el test del hamiltoniano (TEST EFICIENCIA) se debe considerar que dependiendo de
#	 la cantidad de núcleos disponibles, el programa variaría mucho su eficiencia. De hecho, su rendimiento aumenta
#    exponencialmente en relación a los hilos. Para aplicar el test se debe correr:
#		test_Hamiltonian
#
# 3) Si se desea verificar gráficamente el resultado del algoritmo en un grafo pequeño (15 nodos y 0.5 de probabilidad),
#	 se debe correr:
#		test_GraphicallyHamiltonian y GraphicallyHamiltonian.py [DESCOMENTAR AMBOS]
#
# 4) Si se desea aplicar el main (CORRER EL PROGRAMA PRINCIPAL), se debe correr:
#		main y Data.py [DESCOMENTAR AMBOS]
#
# 5) Si se desea ver la diferencia entre ambas probabilidades límite, (log(N)/N) y (1/N)
#	 se debe correr: 
#		test_ProbabilityDifference

run: test_Graph test_Hamiltonian test_GraphicallyHamiltonian Main
# 1)---------------------------------
#	./test_Graph
#	python3 GraphVerifier.py
# 2)---------------------------------
#	./test_Hamiltonian
# 3)---------------------------------
#	./test_GraphicallyHamiltonian
#	python3 GraphicallyHamiltonian.py
# 4)---------------------------------
	./Main
	python3 Data.py
# 5)---------------------------------
#	python3 ProbabilityDifference.py
#------------------------------------

Main: Hamiltonian.o Graph.o Main.o
	g++ $(FLAGS) -o Main Main.cpp Graph.o Hamiltonian.o -pthread

test_GraphicallyHamiltonian: Hamiltonian.o Graph.o test_GraphicallyHamiltonian.cpp
	g++ $(FLAGS) -o test_GraphicallyHamiltonian test_GraphicallyHamiltonian.cpp Hamiltonian.o Graph.o -pthread

test_Hamiltonian: Hamiltonian.o Graph.o test_Hamiltonian.cpp
	g++ $(FLAGS) -o test_Hamiltonian test_Hamiltonian.cpp Hamiltonian.o Graph.o -pthread

test_Graph: Graph.o test_Graph.cpp
	g++ $(FLAGS) -o test_Graph test_Graph.cpp Graph.o

Main.o: Main.cpp
	g++ $(FLAGS) -c Main.cpp

Hamiltonian.o: Hamiltonian.cpp Hamiltonian.h
	g++ $(FLAGS) -c Hamiltonian.cpp -pthread

Graph.o: Graph.cpp
	g++ $(FLAGS) -c Graph.cpp

make clean:
	rm -f *.o test_Graph test_Hamiltonian test_GraphicallyHamiltonian Main 
