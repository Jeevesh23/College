# Using a Python dictionary to act as an adjacency list
graph = {
  'A' : ['B','C','D'],
  'B' : ['A','E','F','C'],
  'C' : ['A','E','F','G'],
  'D' : ['A','G'],
  'E' : ['B','H'],
  'F' : ['B','C','G','F','I'],
  'G' : ['C','G','D','I'],
  'H' : ['E','F','I','K','J'],
  'I' : ['F','G','F','K'],
  'J' : ['J'],
  'K' : ['H','I']
}

visited = [] # Set to keep track of visited nodes of graph.

def dfs(node):  #function for dfs 
    if node not in visited:
        print (node)
        visited.append(node)
        for neighbour in graph[node]:
            dfs(neighbour)


print("Following is the Depth-First Search")
dfs('A')







# Using a Python dictionary to act as an adjacency list
# graph = {
#   '5' : ['3','7'],
#   '3' : ['2', '4'],
#   '7' : ['8'],
#   '2' : [],
#   '4' : ['8'],
#   '8' : []
# }

# visited = set() # Set to keep track of visited nodes of graph.

# def dfs(visited, graph, node):  #function for dfs 
#     if node not in visited:
#         print (node)
#         visited.add(node)
#         for neighbour in graph[node]:
#             dfs(visited, graph, neighbour)

# # Driver Code
# print("Following is the Depth-First Search")
# dfs(visited, graph, '5')


# # importing networkx 
# import networkx as nx
# # importing matplotlib.pyplot
# import matplotlib.pyplot as plt

# Nodes=['a','b','c','d','e','f','g','h']
# Edegs=[('a', 'b'), ('a', 'c'),('a', 'd'),('b', 'e'),('b', 'h'),('c', 'f'),('c', 'g'),('d', 'g')]
# G = nx.Graph()
# G.add_nodes_from(Nodes)
# G.add_edges_from(Edegs)

# stack=[]
# visited={}
# for i in Nodes:
#     visited[i]=0

# # print(visited)
# stack.insert(0,Nodes[0])
# # print(queue)


# while(len(stack)>0):
#     x=stack.pop(0)
#     if(visited[x]==0):
#         adj=list(G.adj[x])
#     # print(adj)
#         for i in adj:
#             if(visited[i]==0):
#                 stack.insert(0,i)
#         visited[x]=1
#         print(x)

# print("adjacency list")
# for i in G.nodes:
#     adj=list(G.adj[i])
#     print(i ,"->",adj)


# nx.draw(G,with_labels = True)
# plt.show()

# def dfs(graph, start):
#     visited = set()  # To keep track of visited nodes
#     stack = [start]   # Stack for DFS

#     while stack:
#         current_node = stack.pop()
        
#         if current_node not in visited:
#             print(current_node, end=' ')
#             visited.add(current_node)
            
#             # Push neighbors into the stack in reverse order to maintain the correct order
#             stack.extend(reversed(graph[current_node]))

# # Example usage:
# # Define an example graph as an adjacency list
# graph = {
#     'A': ['B', 'C'],
#     'B': ['D', 'E'],
#     'C': ['F'],
#     'D': [],
#     'E': ['F'],
#     'F': []
# }

# # Start DFS from node 'A'
# dfs(graph, 'A')

