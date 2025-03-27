# from copy import deepcopy
# # puzzle = [[1, 2, 3],
# #           [8, 6, 0],
# #           [7, 5, 4]]
# # goal = [[1, 2, 3],
# #         [8, 0, 4],
# #         [7, 6, 5]]
# puzzle = [[1, 2, 3],
#                [5, 6, 0],
#                [7, 8, 4]]

# goal = [[1, 2, 3],
#               [5, 8, 6],
#               [0, 7, 4]]

# def heuristic(state):
#     heuristicValue = 0
#     for i in range(3):
#         for j in range(3):
#             goalI, goalJ = findIndex(goal, state[i][j])
#             if state[i][j] != 0:
#                 heuristicValue += abs(goalI - i) + abs(goalJ - j)
#     return heuristicValue

# def findIndex(matrix, value):
#     tempI = 0
#     tempJ = 0
#     for i in range(3):
#         for j in range(3):
#             if matrix[i][j] == value:
#                 tempI = i
#                 tempJ = j
#                 break
#     return (tempI, tempJ)

# def bestFirstSearch8Puzzle(startState):
#     queue = []
#     visited = []
#     queue.append((heuristic(startState), startState))
#     while len(queue) != 0:
#         heuristicValue, state = queue.pop(0)
#         visited.append(state)
#         if state == goal:
#             print("reached goal!!")
#             return
#         print(*state, sep="\n")
#         print()
#         emptyI, emptyJ = findIndex(state, 0)
#         neighbours = []
#         if (emptyI - 1) >= 0:
#             neighbours.append([emptyI - 1, emptyJ])
#         if emptyJ - 1 >= 0:
#             neighbours.append([emptyI, emptyJ - 1])
#         if (emptyI + 1) < 3:
#             neighbours.append([emptyI + 1, emptyJ])
#         if emptyJ + 1 < 3:
#             neighbours.append([emptyI, emptyJ + 1])
#         children = []
#         for i in range(len(neighbours)):
#             swapI, swapJ = neighbours[i]
#             child = deepcopy(state)
#             temp = child[swapI][swapJ]
#             child[swapI][swapJ] = child[emptyI][emptyJ]
#             child[emptyI][emptyJ] = temp
#             children.append(child)
#         for child in children:
#             if child not in visited:
#                 queue.append((heuristic(child), child))
#         queue.sort()
        
# bestFirstSearch8Puzzle(puzzle)

# goal_state = [[1,2,3],
#              [8,0,4],
#              [7,6,5]]

# start_state = [[2,8,1],
#              [0,4,3],
#              [7,6,5]]

# def print_state(state):
#     for row in state:
#         print(row)

# def get_blank_position(state):
#     for i in range(3):
#         for j in range(3):
#             if state[i][j]==0:
#                 return i, j
        

# def gen_moves(state):
#     moves=[]
#     i,j = get_blank_position(state)
#     print(i,j)
 
#     if (i==0):
#         if(j==0):
#             moves.append((i, j+1))
#             moves.append((i+1,0))
#         elif (j==1):
#             moves.append((i, j-1))
#             moves.append((i,j+1))
#             moves.append((i+1,j))
#         elif (j==2):
#             moves.append((i, j-1))
#             moves.append((i+1,j))
#     elif (i==1):
#         if(j==0):
#             moves.append((i, j+1))
#             moves.append((i-1,j))
#             moves.append((i+1,j))
#         elif (j==1):
#             moves.append((i, j-1))
#             moves.append((i,j+1))
#             moves.append((i+1,j))
#             moves.append((i-1,j))
#         elif (j==2):
#             moves.append((i, j-1))
#             moves.append((i+1,j))
#             moves.append((i-1,j))
#     elif(i==2):
#         if(j==0):
#             moves.append((i-1, j))
#             moves.append((i,j+1))
#         elif (j==1):
#             moves.append((i, j-1))
#             moves.append((i,j+1))
#             moves.append((i-1,j))
#         elif (j==2):
#             moves.append((i, j-1))
#             moves.append((i-1,j))

#     return(moves)

# def make_move(state, moves):
#     i,j=get_blank_position(state)
#     n=len(moves)
#     states=[]
    


#     for a in range(n):
#         current=state
#         print_state(state)
#         new_i,new_j=moves[a]
#         print(new_i,new_j)
#         current[i][j],current[new_i][new_j]=state[new_i][new_j],state[i][j]
#         # print_state(current)
#         states.append((current))
#         # print("\n")
#     return states

    



# # print_state(start_state)

# def hill_climbing(start):
#     current_state=start
#     print("Initial State: ")
#     print_state(current_state)

#     if start_state==goal_state:
#         print("Goal reached")

#     moves=[]
#     states=[]
#     states.append(current_state)
#     while(len(states)>0):
#         moves=gen_moves(current_state)
#         print(moves)

#         states=make_move(current_state,moves)
#         for i in range(len(states)):
#             # print_state(states[i])
#             # print("\n")
#             if states[i]==goal_state:
#                 print("Goal state found")
#                 break
#             else:
#                 make_moves(states[i],)

    




# hill_climbing(start_state)



# goal_state = [[1, 2, 3],
#               [8, 0, 4],
#               [7, 6, 5]]

# start_state = [[2, 8, 1],
#                [0, 4, 3],
#                [7, 6, 5]]
#<==============================>#


#case that terminats hill climbing due to failed case
# start_state = [[1, 2, 3],
#               [4, 5, 6],
#               [7, 8, 0]]

# goal_state = [[1, 2, 3],
#                [8, 0, 4],
#                [7, 6, 5]]

#successfull case
start_state = [[1, 2, 3],
               [5, 6, 0],
               [7, 8, 4]]

goal_state = [[1, 2, 3],
              [5, 8, 6],
              [0, 7, 4]]

def print_state(state):
    for row in state:
        print(row)


def get_blank_position(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j


def gen_moves(state):
    moves = []
    i, j = get_blank_position(state)

    if i == 0:
        if j == 0:
            moves.append((i, j + 1))
            moves.append((i + 1, 0))
        elif j == 1:
            moves.append((i, j - 1))
            moves.append((i, j + 1))
            moves.append((i + 1, j))
        elif j == 2:
            moves.append((i, j - 1))
            moves.append((i + 1, j))
    elif i == 1:
        if j == 0:
            moves.append((i, j + 1))
            moves.append((i - 1, j))
            moves.append((i + 1, j))
        elif j == 1:
            moves.append((i, j - 1))
            moves.append((i, j + 1))
            moves.append((i + 1, j))
            moves.append((i - 1, j))
        elif j == 2:
            moves.append((i, j - 1))
            moves.append((i + 1, j))
            moves.append((i - 1, j))
    elif i == 2:
        if j == 0:
            moves.append((i - 1, j))
            moves.append((i, j + 1))
        elif j == 1:
            moves.append((i, j - 1))
            moves.append((i, j + 1))
            moves.append((i - 1, j))
        elif j == 2:
            moves.append((i, j - 1))
            moves.append((i - 1, j))

    return moves


def make_move(state, moves):
    i, j = get_blank_position(state)
    states = []

    for new_i, new_j in moves:
        current = [row[:] for row in state]
        current[i][j], current[new_i][new_j] = current[new_i][new_j], current[i][j]
        states.append(current)
    return states


def manhattan_distance(state, goal_state):
    total_distance = 0

    # Create dictionaries to store the position of each number in the goal state
    goal_positions = {}
    for i in range(3):
        for j in range(3):
            goal_positions[goal_state[i][j]] = (i, j)

    # Calculate Manhattan distance for each tile in the current state
    for i in range(3):
        for j in range(3):
            if state[i][j] != 0:  # Ignore the empty tile
                num = state[i][j]
                goal_pos = goal_positions[num]
                distance = abs(i - goal_pos[0]) + abs(j - goal_pos[1])
                total_distance += distance

    return total_distance

def hill_climbing(start):
    # Define a class to represent a state in the search
    class State:
        def __init__(self, state, parent=None, heuristic=0):
            self.state = state
            self.parent = parent
            self.heuristic = heuristic

    current_state = State(start_state)  # Start state
    print("Initial State: ")
    print_state(current_state.state)

    if start_state == goal_state:
        print("Goal reached")
        return

    open = [current_state]  # open to store states to be explored

    while open:
        open.sort(key=lambda x: x.heuristic)  # Sort open based on heuristic values
        current_state = open.pop(0)  # Pop the state with the lowest heuristic value
        print("Current State: ")
        print_state(current_state.state)
        print("Heuristic value = " + str(current_state.heuristic))

        if current_state.state == goal_state:
            print("Goal state found.")
            print("Final state: ")
            print_state(goal_state)
            break

        moves = gen_moves(current_state.state)
        for move in moves:
            new_state = make_move(current_state.state, [move])[0]
            heuristic_value = manhattan_distance(new_state, goal_state)
            new_state_obj = State(new_state, current_state, heuristic_value)
            open.append(new_state_obj)

    # Trace back the path to the start state
    path = []
    while current_state:
        path.append(current_state.state)
        current_state = current_state.parent

    # Reverse the path to get the correct sequence of steps
    path.reverse()

    print("Sequence of steps to reach the goal state:")
    for step in path:
        print_state(step)
        print()

# Test the hill climbing function
hill_climbing(start_state)
