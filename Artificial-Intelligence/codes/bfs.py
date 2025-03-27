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

visited = []
queue = []

def bfs(node):
    visited.append(node)
    queue.append(node)

    while len(queue)>0:
        m = queue.pop(0)
        print(m, end = " ")

        for neighbour in graph[m]:
            if neighbour not in visited:
                visited.append(neighbour)
                queue.append(neighbour)

print("Following is the Breadth-First Search")
bfs('A')    # function calling


# using matplotlib
# # importing networkx 
# import networkx as nx
# # importing matplotlib.pyplot
# import matplotlib.pyplot as plt

# Nodes=['a','b','c','d','e','f','g','h']
# Edegs=[('a', 'b'), ('a', 'c'),('a', 'd'),('b', 'e'),('b', 'h'),('c', 'f'),('c', 'g'),('d', 'g')]
# G = nx.Graph()
# G.add_nodes_from(Nodes)
# G.add_edges_from(Edegs)

# queue=[]
# visited={}
# for i in Nodes:
#     visited[i]=0

# # print(visited)
# queue.append(Nodes[0])
# # print(queue)


# while(len(queue)>0):
#     x=queue.pop(0)
#     adj=list(G.adj[x])
#     # print(adj)
#     for i in adj:
#         if(visited[i]==0):
#             queue.append(i)
#     visited[x]=1
#     print(x)

# print("adjacency list")
# for i in G.nodes:
#     adj=list(G.adj[i])
#     print(i ,"->",adj)

# nx.draw(G,with_labels = True)
# plt.show()
