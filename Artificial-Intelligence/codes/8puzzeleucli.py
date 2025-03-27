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

import math

goal_state = [[1, 2, 3],
              [5, 8, 6],
              [0, 7, 4]]

start_state = [[1, 2, 3],
               [5, 6, 0],
               [7, 8, 4]]


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


def hill_climbing(start):
    current_state = start
    print("Initial State: ")
    print_state(current_state)

    if start_state == goal_state:
        print("Goal reached")
    
    i=0

    while True:
        moves = gen_moves(current_state)
        next_states = make_move(current_state, moves)
        min_heuristic = float('inf')
        next_state = None

        for state in next_states:
            heuristic = sum(math.sqrt((state[i][j] // 3 - goal_state[i][j] // 3)**2 + (state[i][j] % 3 - goal_state[i][j] % 3)**2) for i in range(3) for j in range(3))
            if heuristic < min_heuristic:
                min_heuristic = heuristic
                next_state = state

        if min_heuristic > 0:
            current_state = next_state
            print("Next State: ")
            print_state(current_state)
        else:
            print("Goal state found.")
            print("Final state: ")
            print_state(goal_state)
            break

        i=i+1


hill_climbing(start_state)
