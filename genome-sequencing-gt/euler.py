import matplotlib.pyplot as plt
import networkx as nx

H = ["AAT", "TGC", "CAA", "GCT", "CCA", "CTA", "TCC", "TAG", "AGT", "TCC", "TTT", "TTC"]

distinct_prefixes = set()
distinct_suffixes = set()

for sequence in H:
    prefix = sequence[:2]
    suffix = sequence[1:]
    distinct_prefixes.add(prefix)
    distinct_suffixes.add(suffix)

V = sorted(distinct_prefixes.union(distinct_suffixes))

# Create an empty list to store edges
edges = []

# Connect prefixes to suffixes
for sequence in H:
    prefix = sequence[:2]
    suffix = sequence[1:]
    edges.append((prefix, suffix))

# Create a graph visualization
G = nx.DiGraph()
G.add_edges_from(edges)

# Draw the graph using Matplotlib with a specified seed for consistent layout
seed = 42  # You can change this seed to get different consistent layouts
pos = nx.spring_layout(G, seed=seed)
nx.draw(G, pos, with_labels=True, node_size=500, node_color='lightblue')
plt.title("Graph of Prefixes and Suffixes")
plt.show()
