#water jug problem using DFS

A = int(input("Enter the maximum capacity of container A: "))
B = int(input("Enter the maximum capacity of container B: "))
target = int(input("Enter the required capacity: "))

visited = set()

def DFS(a , b , A , B , target , visited):
    if a == target or b == target:
        return [[(a,b)]]
    
    visited.add((a,b))

    next_states = []

    #empty A
    if (0,b) not in visited:
        next_states.append((0,b))

    #empty B
    if (a,0) not in visited:
        next_states.append((a,0))

    #fill A
    if (A,b) not in visited:
        next_states.append((A,b))

    #fill B
    if (a,B) not in visited:
        next_states.append((a,B))

    #A to B
    if a+b>=B:
        if (a-(B-b),B) not in visited:
            next_states.append((a-(B-b),B))
    else:
        if (0,a+b) not in visited:
            next_states.append((0,a+b))

    #B to A
    if a+b>=A:
        if (A,b-(A-a)) not in visited:
            next_states.append((A,b-(A-a)))
    else:
        if (a+b,0) not in visited:
            next_states.append((a+b,0))

    all_paths = []
    for state in next_states:
        paths = DFS(state[0],state[1],A,B,target,visited)
        if paths:
            for path in paths:
                all_paths.append([(a,b)] + path)
        
    return all_paths

paths = DFS(0,0,A,B,target,visited)
if paths:
    print("All Solutions:")
    for path in paths:
        print([step for step in path])
else:
    print("No solution found")
