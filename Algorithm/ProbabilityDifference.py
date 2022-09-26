import numpy as np
from matplotlib import pyplot as plt

N = np.arange(3, 5000, 1)
N_log = []
N_1_divided_N = []
for i in N:
    N_log.append(np.log(i)/i)
    N_1_divided_N.append(1/i)

plt.figure(figsize=(10, 7))
plt.grid(True)
plt.xlabel('Número de nodos', fontsize=15)
plt.ylabel('Probabilidad límite $P_{lim}$', fontsize=15)
plt.title('Umbral de aparición de ciclos Hamiltonianos en Grafos aleatorios', fontsize=18)
# draw to plots for log(N)/N and 1/N
plt.plot(N, N_log, 'red', label='$log(N)/N$')
plt.plot(N, N_1_divided_N, 'b', label='$1/N$')
plt.legend(fontsize=13)
plt.show()

print(N_log[-1])
