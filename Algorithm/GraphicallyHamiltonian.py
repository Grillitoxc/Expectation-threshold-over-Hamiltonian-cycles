import networkx as nx
from matplotlib import colors, pyplot as plt

plt.figure(figsize=(10, 8))
plt.title('Hamiltonian path in a random graph with probability 0.18 and 15 nodes')

G = nx.Graph()
with open('graphically_hamiltonian_graph.txt', 'r') as f:
    for line in f:
        line = line.split()
        G.add_edge(int(line[0]), int(line[1]), color='black')
pos = nx.spring_layout(G)

with open('graphically_hamiltonian.txt', 'r') as f:
    edges = []
    while True:
        line = f.readline()
        if not line:
            break
        edges.append(int(line))
    # add the edges to the graph
    for i in range(len(edges)-1):
        # color the nodes blue
        G.add_edge(edges[i], edges[i+1], color='blue')
        i += 1


colors = nx.get_edge_attributes(G, 'color').values()
color_node_initial = []

if edges == []:
    quit()

i = 0
while i<len(G.nodes()):
    if (list(G.nodes())[i] == edges[0]):
        color_node_initial.append('green')
    else:
        color_node_initial.append('red')
    i += 1

nx.draw_networkx_labels(G, pos, font_size=10, font_family='sans-serif', font_weight='bold', font_color='white')
nx.draw_networkx_nodes(G, pos, node_color=color_node_initial , node_size=400)
nx.draw_networkx_edges(G, pos, edge_color=colors , width=1, style='solid')

plt.show()
