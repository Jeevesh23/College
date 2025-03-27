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

class GraphGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Directed Graph GUI")

        self.nodes = ["AAT", "GCG", "GCA", "ATG", "TGG", "TGC", "GGC", "GTG", "CGT", "CAA"]
        self.graph = Graph(self.nodes)

        self.create_widgets()
        self.draw_graph()

    def create_widgets(self):
        self.draw_button = tk.Button(self.root, text="Draw Directed Graph", command=self.draw_graph)
        self.draw_button.pack()

        # Create a canvas for graph visualization
        self.figure, self.ax = plt.subplots(figsize=(6, 6))
        self.canvas = FigureCanvasTkAgg(self.figure, master=self.root)
        self.canvas.get_tk_widget().pack()

    def draw_graph(self):
        pos = nx.spring_layout(self.graph.graph, seed=42)  # Using a fixed seed for consistent layout
        nx.draw(self.graph.graph, pos, with_labels=True, node_size=2000, node_color='lightblue', font_size=10, font_color='black', font_weight='bold', connectionstyle="arc3, rad = 0.2")
        plt.axis('off')
        self.canvas.draw()

if __name__ == "__main__":
    root = tk.Tk()
    app = GraphGUI(root)
    root.mainloop()
