import tkinter as tk
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

class Graph:
    def __init__(self):
        self.graph = {}

    def add_node(self, node):
        if node not in self.graph:
            self.graph[node] = []

    def add_edge(self, node1, node2):
        self.graph[node1].append(node2)

    def find_matching_suffix_prefix(self):
        for node1 in self.graph:
            suffix1 = node1[-2:]
            for node2 in self.graph:
                prefix2 = node2[:2]
                if suffix1 == prefix2:
                    self.add_edge(node1, node2)

    def print_graph(self):
        for node in self.graph:
            print(f"{node} -> {', '.join(self.graph[node])}")

    def adjacency_matrix(self):
        nodes = list(self.graph.keys())
        num_nodes = len(nodes)

        matrix = [[0] * num_nodes for _ in range(num_nodes)]

        for i, node1 in enumerate(nodes):
            for j, node2 in enumerate(nodes):
                if node2 in self.graph[node1]:
                    matrix[i][j] = 1

        return matrix

    def semi_hamiltonian_path(self):
        nodes = list(self.graph.keys())
        num_nodes = len(nodes)

        def dfs(current_node, visited, path):
            visited[current_node] = True
            path.append(current_node)

            if len(path) == num_nodes:
                return path

            for neighbor in self.graph[current_node]:
                if not visited[neighbor]:
                    result = dfs(neighbor, visited, path)
                    if result:
                        return result

            visited[current_node] = False
            path.pop()
            return None

        for start_node in nodes:
            visited = {node: False for node in nodes}
            path = []
            result = dfs(start_node, visited, path)
            if result:
                return result

        return None

class GraphGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Graph GUI")

        self.graph = Graph()
        self.nodes = ["AAT", "GCG", "GCA", "ATG", "TGG", "TGC", "GGC", "GTG", "CGT", "CAA"]
        self.G = nx.Graph()

        self.create_widgets()

    def create_widgets(self):
        self.add_button = tk.Button(self.root, text="Add Node", command=self.add_node)
        self.add_button.pack()

        self.find_matching_button = tk.Button(self.root, text="Find Matching Suffix-Prefix", command=self.find_matching_suffix_prefix)
        self.find_matching_button.pack()

        self.print_graph_button = tk.Button(self.root, text="Print Graph", command=self.print_graph)
        self.print_graph_button.pack()

        self.adjacency_matrix_button = tk.Button(self.root, text="Adjacency Matrix", command=self.print_adjacency_matrix)
        self.adjacency_matrix_button.pack()

        self.path_button = tk.Button(self.root, text="Find Semi-Hamiltonian Path", command=self.find_semi_hamiltonian_path)
        self.path_button.pack()

        self.text = tk.Text(self.root, height=10, width=40)
        self.text.pack()

        # Create a canvas for graph visualization
        self.figure, self.ax = plt.subplots(figsize=(6, 6))
        self.canvas = FigureCanvasTkAgg(self.figure, master=self.root)
        self.canvas.get_tk_widget().pack()

    def add_node(self):
        node = self.nodes.pop(0)
        self.graph.add_node(node)
        self.update_graph()
        self.text.insert(tk.END, f"Added Node: {node}\n")

    def find_matching_suffix_prefix(self):
        self.graph.find_matching_suffix_prefix()
        self.update_graph()
        self.text.insert(tk.END, "Matching Suffix-Prefix: Operation Complete\n")

    def print_graph(self):
        for node in self.graph.graph:
            self.text.insert(tk.END, f"{node} -> {', '.join(self.graph.graph[node])}\n")

    def print_adjacency_matrix(self):
        adj_matrix = self.graph.adjacency_matrix()
        for row in adj_matrix:
            self.text.insert(tk.END, ' '.join(map(str, row)) + '\n')

    def find_semi_hamiltonian_path(self):
        semi_hamiltonian_path = self.graph.semi_hamiltonian_path()
        if semi_hamiltonian_path:
            self.text.insert(tk.END, "Semi-Hamiltonian Path:\n")
            self.text.insert(tk.END, ' -> '.join(semi_hamiltonian_path))
        else:
            self.text.insert(tk.END, "No Semi-Hamiltonian Path Found")

    def update_graph(self):
        self.add_button.config(text=f"Add Node ({len(self.nodes)} remaining)")

    def draw_graph(self):
        self.G.clear()
        for node in self.graph.graph:
            self.G.add_node(node)
            for neighbor in self.graph.graph[node]:
                self.G.add_edge(node, neighbor)

        pos = nx.spring_layout(self.G)
        nx.draw(self.G, pos, with_labels=True, node_size=2000, node_color='lightblue', font_size=10, font_color='black', font_weight='bold')
        plt.axis('off')
        self.canvas.draw()

if __name__ == "__main__":
    root = tk.Tk()
    app = GraphGUI(root)
    root.mainloop()
