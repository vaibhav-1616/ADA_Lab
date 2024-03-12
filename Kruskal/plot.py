import matplotlib.pyplot as plt
import networkx as nx

# Original edges with weights (from your C++ input)
original_edges = {
    (0, 1): 10,
    (0, 2): 20,
    (1, 2): 30,
    (1, 3): 5,
    (2, 3): 15,
    (3, 4): 6
}

# Edges included in MST (output of Kruskal's)
mst_edges = [
    (1, 3),
    (3, 4),
    (0, 1),
    (2, 3)
]

# Create a graph
G = nx.Graph()

# Add only MST edges with their correct weights
for u, v in mst_edges:
    weight = original_edges.get((u, v)) or original_edges.get((v, u))
    G.add_edge(u, v, weight=weight)

# Draw the MST
pos = nx.spring_layout(G, seed=42)
plt.figure(figsize=(8, 6))
nx.draw(G, pos, with_labels=True, node_size=800, node_color="lightgreen", font_size=12)
edge_labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_color='blue')

plt.title("Minimum Spanning Tree (Kruskal's Algorithm)")
plt.axis('off')
plt.tight_layout()
plt.show()
