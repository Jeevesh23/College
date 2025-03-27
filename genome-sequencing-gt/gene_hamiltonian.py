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

# Example usage:
if __name__ == "__main__":
    g = Graph()
    nodes = ["AAT", "GCG", "GCA", "ATG", "TGG", "TGC", "GGC", "GTG", "CGT", "CAA"]

    for node in nodes:
        g.add_node(node)

    g.find_matching_suffix_prefix()

    g.print_graph()

    adj_matrix = g.adjacency_matrix()

    print("\nAdjacency Matrix:")
    for row in adj_matrix:
        print(row)

    semi_hamiltonian_path = g.semi_hamiltonian_path()

    if semi_hamiltonian_path:
        print("\nSemi-Hamiltonian Path:")
        for node in semi_hamiltonian_path:
            print(node)
    else:
        print("\nNo Semi-Hamiltonian Path Found")
