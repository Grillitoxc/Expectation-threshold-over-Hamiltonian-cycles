import networkx as nx
from matplotlib import pyplot as plt

plt.figure(figsize=(10, 7))

G = nx.Graph()
with open('generated_graph.txt', 'r') as f:
    for line in f:
        line = line.split()
        G.add_edge(int(line[0]), int(line[1]))
pos = nx.spring_layout(G)

nx.draw_networkx_labels(G, pos, font_size=10, font_family='sans-serif', font_weight='bold', font_color='white')
nx.draw_networkx_nodes(G, pos, node_size=400)
nx.draw_networkx_edges(G, pos, edge_color='black', width=0.5, style='solid')

plt.show()
