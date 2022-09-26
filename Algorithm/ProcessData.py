import numpy as np
import statistics as st
from matplotlib import pyplot as plt

y = np.loadtxt('probabilities.txt', usecols=0)

array = np.unique(y, return_counts=True)

plt.figure(figsize=(10, 7))
plt.hist(y, bins=100, color='g', label='Probability', linewidth=0.5)
plt.axvline(x=st.mean(y), color='r', linestyle='-', label='Mean')
plt.axvline(x=st.median(y), color='b', linestyle='-', label='Median')
plt.xlabel('Probability')
plt.ylabel('Frequency')
plt.title('Probability of finding a Hamiltonian path given a random graph with 15 nodes', fontsize=15)
plt.legend()
plt.show()
