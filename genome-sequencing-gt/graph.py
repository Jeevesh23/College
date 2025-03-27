# Define a class called 'Graph' to represent a graph data structure.
class Graph:
    # Constructor method to initialize the graph with an empty dictionary.
    def __init__(self):
        self.graph = {}

    # Method to add a node to the graph.
    def add_node(self, node):
        # Check if the node is not already in the graph and add it with an empty list of edges.
        if node not in self.graph:
            self.graph[node] = []

    # Method to add an edge between two nodes in the graph.
    def add_edge(self, node1, node2):
        # Add 'node2' to the list of edges for 'node1'.
        self.graph[node1].append(node2)

    # Method to find and connect nodes with matching suffixes and prefixes.
    def find_matching_suffix_prefix(self):
        # Iterate over each node in the graph.
        for node1 in self.graph:
            # Extract the last two characters (suffix) of 'node1'.
            suffix1 = node1[-2:]
            # Iterate over each node in the graph again.
            for node2 in self.graph:
                # Extract the first two characters (prefix) of 'node2'.
                prefix2 = node2[:2]
                # Check if the suffix of 'node1' matches the prefix of 'node2'.
                if suffix1 == prefix2:
                    # If they match, add an edge between 'node1' and 'node2'.
                    self.add_edge(node1, node2)

    # Method to print the graph.
    def print_graph(self):
        # Iterate over each node in the graph.
        for node in self.graph:
            # Print the node and its list of connected nodes (edges).
            print(f"{node} -> {', '.join(self.graph[node])}")


# Example usage:
if __name__ == "__main__":
    # Create an instance of the 'Graph' class.
    g = Graph()

    # Define a list of nodes to be added to the graph.
    nodes = ["AAT", "GCG", "GCA", "ATG", "TGG", "TGC", "GGC", "GTG", "CGT", "CAA"]

    # Add each node to the graph.
    for node in nodes:
        g.add_node(node)

    # Find and add edges between nodes with matching suffixes and prefixes.
    g.find_matching_suffix_prefix()

    # Print the resulting graph.
    g.print_graph()
