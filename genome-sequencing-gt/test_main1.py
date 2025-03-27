import tkinter as tk
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

class Graph:
    def __init__(self, nodes):
        self.graph = nx.DiGraph()
        self.nodes = nodes

        self.create_edges()

    def create_edges(self):
        for node1 in self.nodes:
            suffix1 = node1[-2:]
            for node2 in self.nodes:
                prefix2 = node2[:2]
                if suffix1 == prefix2 and node1 != node2:
                    self.graph.add_edge(node1, node2)

    def find_semi_hamiltonian_path(self):
        semi_hamiltonian_path = []
        for node in self.nodes:
            path = [node]
            visited = set([node])
            if self.dfs(node, path, visited):
                return path
        return None

    def dfs(self, current_node, path, visited):
        if len(path) == len(self.nodes):
            return True
        for neighbor in self.graph.neighbors(current_node):
            if neighbor not in visited:
                path.append(neighbor)
                visited.add(neighbor)
                if self.dfs(neighbor, path, visited):
                    return True
                path.pop()
                visited.remove(neighbor)
        return False

class GraphGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Directed Graph GUI")

        self.nodes = ["AAT", "GCG", "GCA", "ATG", "TGG", "TGC", "GGC", "GTG", "CGT", "CAA"]
        self.graph = Graph(self.nodes)

        self.create_widgets()

    def create_widgets(self):
        self.draw_button = tk.Button(self.root, text="Draw Directed Graph", command=self.draw_graph)
        self.draw_button.pack()

        self.find_path_button = tk.Button(self.root, text="Find Semi-Hamiltonian Path", command=self.find_semi_hamiltonian_path)
        self.find_path_button.pack()

        self.sequence_label = tk.Label(self.root, text="Semi-Hamiltonian Path Sequence: ")
        self.sequence_label.pack()

        # Create a canvas for the graph visualization
        self.figure, self.ax = plt.subplots(figsize=(8, 8))
        self.canvas = FigureCanvasTkAgg(self.figure, master=self.root)
        self.canvas.get_tk_widget().pack()

        # Create a separate canvas for the semi-Hamiltonian path
        self.path_figure, self.path_ax = plt.subplots(figsize=(8, 8))
        self.path_canvas = FigureCanvasTkAgg(self.path_figure, master=self.root)
        self.path_canvas.get_tk_widget().pack()

    def draw_graph(self):
        pos = nx.spring_layout(self.graph.graph, seed=42, k=0.3)
        nx.draw(self.graph.graph, pos, with_labels=True, node_size=2000, node_color='lightblue', font_size=10, font_color='black', font_weight='bold', connectionstyle="arc3, rad = 0.2")
        plt.axis('off')
        self.canvas.draw()

    def find_semi_hamiltonian_path(self):
        semi_hamiltonian_path = self.graph.find_semi_hamiltonian_path()
        if semi_hamiltonian_path:
            sequence = ' -> '.join(semi_hamiltonian_path)
            self.sequence_label.config(text=f"Semi-Hamiltonian Path Sequence: {sequence}")

            # Highlight nodes in the semi-Hamiltonian path in a separate graph
            self.highlight_path(semi_hamiltonian_path)
        else:
            self.sequence_label.config(text="No Semi-Hamiltonian Path Found")

    def highlight_path(self, path):
        pos = nx.spring_layout(self.graph.graph, seed=42, k=0.3)
        node_colors = ['lightblue' if node not in path else 'red' for node in self.nodes]

        nx.draw(self.graph.graph, pos, with_labels=True, node_size=2000, node_color=node_colors, font_size=10, font_color='black', font_weight='bold', connectionstyle="arc3, rad = 0.2")
        plt.axis('off')
        self.canvas.draw()

        # Create a separate graph for the path
        path_graph = nx.DiGraph()
        path_graph.add_nodes_from(path)
        for i in range(len(path) - 1):
            path_graph.add_edge(path[i], path[i + 1])

        pos_path = nx.spring_layout(path_graph, k=0.3)
        nx.draw(path_graph, pos_path, with_labels=True, node_size=2000, node_color='red', font_size=10, font_color='black', font_weight='bold', connectionstyle="arc3, rad = 0.2")
        plt.axis('off')
        self.path_canvas.draw()

if __name__ == "__main__":
    root = tk.Tk()
    app = GraphGUI(root)
    root.mainloop()
