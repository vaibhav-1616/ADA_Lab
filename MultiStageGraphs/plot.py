import matplotlib.pyplot as plt
import networkx as nx

# Define the graph edges with weights
edges = [
    (0, 1, 7), (0, 2, 5), (0, 3, 1),
    (1, 4, 2), (1, 5, 3),
    (2, 4, 6), (2, 5, 7),
    (3, 4, 4), (3, 5, 8), (3, 6, 9),
    (4, 7, 6),
    (5, 7, 4),
    (6, 7, 2)
]

# Create directed graph
G = nx.DiGraph()

# Add edges and weights to graph
for u, v, w in edges:
    G.add_edge(u, v, weight=w)

# Manually define positions for a layered layout
positions = {
    0: (0, 0),
    1: (1, 1),
    2: (1, 0),
    3: (1, -1),
    4: (2, 1),
    5: (2, 0),
    6: (2, -1),
    7: (3, 0)
}

# Draw the graph
plt.figure(figsize=(10, 5))
nx.draw(G, pos=positions, with_labels=True, node_size=700, node_color="skyblue", arrows=True)
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos=positions, edge_labels=edge_labels)

plt.title("Multistage Graph")
plt.axis('off')
plt.tight_layout()
plt.show()
