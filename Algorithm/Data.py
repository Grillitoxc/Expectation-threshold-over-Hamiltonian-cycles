import numpy as np
from matplotlib import pyplot as plt

x = np.arange(1, 10001, 1)
y = np.loadtxt('probabilities.txt', usecols=0)
plt.figure(figsize=(10, 7))
plt.grid(True)
plt.xlabel('Iteration number') 
plt.ylabel('Conection probability')
plt.title('Probability ($P_k$) of finding a Hamiltonian path given a random graph with 15 nodes', fontsize=15)
plt.axhline(y=0.18, color='b', linestyle='-', label='Conjeture')
plt.plot(x, y, 'r-o', label='Probability', linewidth=0.3)
plt.legend()
plt.show()

x = np.arange(1, 1001, 1)
y = np.loadtxt('probabilitiesN13.txt', usecols=0)
plt.figure(figsize=(10, 7))
plt.grid(True)
plt.xlabel('Iteration number') 
plt.ylabel('Conection probability')
plt.title('Probability of finding a Hamiltonian path given a random graph with 13 nodes', fontsize=15)
plt.axhline(y=0.18, color='b', linestyle='-', label='Conjeture')
plt.plot(x, y, 'r-o', label='Probability', linewidth=0.5)
plt.legend()
plt.show()

x = np.arange(1, 1001, 1)
y = np.loadtxt('probabilitiesN14.txt', usecols=0)
plt.figure(figsize=(10, 7))
plt.grid(True)
plt.xlabel('Iteration number') 
plt.ylabel('Conection probability')
plt.title('Probability of finding a Hamiltonian path given a random graph with 14 nodes', fontsize=15)
plt.axhline(y=0.18, color='b', linestyle='-', label='Conjeture')
plt.plot(x, y, 'r-o', label='Probability', linewidth=0.5)
plt.legend()
plt.show()

x = np.arange(1, 1001, 1)
y = np.loadtxt('probabilitiesN15.txt', usecols=0)
plt.figure(figsize=(10, 7))
plt.grid(True)
plt.xlabel('Iteration number') 
plt.ylabel('Conection probability')
plt.title('Probability of finding a Hamiltonian path given a random graph with 15 nodes', fontsize=15)
plt.axhline(y=0.18, color='b', linestyle='-', label='Conjeture')
plt.plot(x, y, 'r-o', label='Probability', linewidth=0.5)
plt.legend()
plt.show()

x = np.arange(1, 1001, 1)
y = np.loadtxt('probabilitiesN16.txt', usecols=0)
plt.figure(figsize=(10, 7))
plt.grid(True)
plt.xlabel('Iteration number') 
plt.ylabel('Conection probability')
plt.title('Probability of finding a Hamiltonian path given a random graph with 16 nodes', fontsize=15)
plt.axhline(y=0.18, color='b', linestyle='-', label='Conjeture')
plt.plot(x, y, 'r-o', label='Probability', linewidth=0.5)
plt.legend()
plt.show()

x = np.arange(1, 1001, 1)
y = np.loadtxt('probabilitiesN17.txt', usecols=0)
plt.figure(figsize=(10, 7))
plt.grid(True)
plt.xlabel('Iteration number') 
plt.ylabel('Conection probability')
plt.title('Probability of finding a Hamiltonian path given a random graph with 17 nodes', fontsize=15)
plt.axhline(y=0.18, color='b', linestyle='-', label='Conjeture')
plt.plot(x, y, 'r-o', label='Probability', linewidth=0.5)
plt.legend()
plt.show()

x = np.arange(1, 1001, 1)
y = np.loadtxt('probabilitiesN18.txt', usecols=0)
plt.figure(figsize=(10, 7))
plt.grid(True)
plt.xlabel('Iteration number') 
plt.ylabel('Conection probability')
plt.title('Probability of finding a Hamiltonian path given a random graph with 18 nodes', fontsize=15)
plt.axhline(y=0.18, color='b', linestyle='-', label='Conjeture')
plt.plot(x, y, 'r-o', label='Probability', linewidth=0.5)
plt.legend()
plt.show()

x = np.arange(1, 1001, 1)
y = np.loadtxt('probabilitiesN19.txt', usecols=0)
plt.figure(figsize=(10, 7))
plt.grid(True)
plt.xlabel('Iteration number') 
plt.ylabel('Conection probability')
plt.title('Probability of finding a Hamiltonian path given a random graph with 19 nodes', fontsize=15)
plt.axhline(y=0.18, color='b', linestyle='-', label='Conjeture')
plt.plot(x, y, 'r-o', label='Probability', linewidth=0.5)
plt.legend()
plt.show()
