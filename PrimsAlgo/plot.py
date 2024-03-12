import matplotlib.pyplot as plt
import networkx as nx

# The result of Prim's algorithm (edges in MST)
mst_edges = [
    (1, 0, 2),
    (1, 2, 3),
    (1, 4, 5),
    (4, 3, 2)
]

# Create a graph
G = nx.Graph()

# Add edges with weights
for u, v, w in mst_edges:
    G.add_edge(u, v, weight=w)

# Draw the graph
pos = nx.spring_layout(G)  # Automatically choose layout
plt.figure(figsize=(8, 6))
nx.draw(G, pos, with_labels=True, node_color="skyblue", node_size=800, font_size=12)
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_color='red')

plt.title("Minimum Spanning Tree (Prim's Algorithm)")
plt.axis('off')
plt.tight_layout()
plt.show()
