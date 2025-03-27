#water jug problem using BFS

visited = []
traversal = []
parent_state = {}


A = int(input("Enter the maximum capacity of container A: "))
B = int(input("Enter the maximum capacity of container B: "))
target = int(input("Enter the required capacity: "))

def moves(state):
 a , b = state
 possible_moves = []
 

 #empty A
 if (0,b) not in visited:
  possible_moves.append((0,b))

 #empty B
 if (a,0) not in visited:
  possible_moves.append((a,0))

 #fill A
 if (A,b) not in visited:
  possible_moves.append((A,b))

 #fill B
 if (a,B) not in visited:
  possible_moves.append((a,B))

 #A to B
 if a+b>=B:
  if (a-(B-b),B) not in visited:
   possible_moves.append((a-(B-b),B))
 else:
  if (0,a+b) not in visited:
   possible_moves.append((0,a+b))

 #B to A
 if a+b>=A:
  if (A,b-(A-a)) not in visited:
   possible_moves.append((A,b-(A-a)))
 else:
  if (a+b,0) not in visited:
   possible_moves.append((a+b,0))

 return possible_moves

def BFS():
 start = (0,0)
 open = [start]
 visited.append(start)
 found_solution = False
 path = []

 while open:
  current = open.pop(0)
  traversal.append(current)

  if target in current:
   found_solution = True
   path = [current]
   while current != start:
    path.insert(1,current)
    current = parent_state[current]
   path.insert(1,start)
   print("solution found : " , end=" ")
   for state in path:
    print(state, end=" -> " if state != path[-1] else "\n")
   continue
   
  next_moves = moves(current)
  for move in next_moves:
   if move not in visited:
    open.append(move)
    visited.append(move)
    parent_state[move] = current
  
 if not found_solution:
    print("No solution")


BFS()