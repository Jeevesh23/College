import tkinter as tk
import networkx as nx
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import tkinter.simpledialog

class Graph:
    def __init__(self):
        self.graph = nx.Graph()

    def add_node(self, node):
        self.graph.add_node(node)

    def add_edge(self, node1, node2):
        self.graph.add_edge(node1, node2)

class GraphGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Graph GUI")

        self.graph = Graph()

        self.create_widgets()

    def create_widgets(self):
        self.add_node_button = tk.Button(self.root, text="Add Node", command=self.add_node)
        self.add_node_button.pack()

        self.add_edge_button = tk.Button(self.root, text="Add Edge", command=self.add_edge)
        self.add_edge_button.pack()

        self.draw_button = tk.Button(self.root, text="Draw Graph", command=self.draw_graph)
        self.draw_button.pack()

        # Create a canvas for graph visualization
        self.figure, self.ax = plt.subplots(figsize=(6, 6))
        self.canvas = FigureCanvasTkAgg(self.figure, master=self.root)
        self.canvas.get_tk_widget().pack()

    def add_node(self):
        node = tk.simpledialog.askstring("Add Node", "Enter a node name:")
        if node:
            self.graph.add_node(node)

    def add_edge(self):
        node1 = tk.simpledialog.askstring("Add Edge", "Enter the first node name:")
        node2 = tk.simpledialog.askstring("Add Edge", "Enter the second node name:")
        if node1 and node2:
            self.graph.add_edge(node1, node2)

    def draw_graph(self):
        pos = nx.spring_layout(self.graph.graph)
        nx.draw(self.graph.graph, pos, with_labels=True, node_size=2000, node_color='lightblue', font_size=10, font_color='black', font_weight='bold')
        plt.axis('off')
        self.canvas.draw()

if __name__ == "__main__":
    root = tk.Tk()
    app = GraphGUI(root)
    root.mainloop()
