#case that terminats hill climbing due to failed case
start_state = [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 0]]

goal_state = [[1, 2, 3],
               [8, 0, 4],
               [7, 6, 5]]

#successfull case
# start_state = [[1, 2, 3],
#                [5, 6, 0],
#                [7, 8, 4]]

# goal_state = [[1, 2, 3],
#               [5, 8, 6],
#               [0, 7, 4]]

import math

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
                # distance = math.sqrt((abs(i-goal_pos[0])**2 + (abs(j-goal_pos[1])**2) => euclidian distance
                total_distance += distance

    return total_distance



def hill_climbing(start):
    current_state = start
    print("Initial State: ")
    print_state(current_state)

    if start_state == goal_state:
        print("Goal reached")
    
    prev_heuristic = None

    while True:
        moves = gen_moves(current_state)
        next_states = make_move(current_state, moves)
        min_heuristic = float('inf')
        next_state = None

        for state in next_states:
            heuristic = manhattan_distance(state, goal_state)
            if heuristic < min_heuristic:
                min_heuristic = heuristic
                next_state = state
                
        if prev_heuristic is not None and min_heuristic >= prev_heuristic:
            print("No better state found. Terminating.")
            break

        prev_heuristic=min_heuristic

        if min_heuristic > 0:
            current_state = next_state
            print("Next State: ")
            print_state(current_state)
            print("Heuritic value = "+ str(min_heuristic))
        else:
            print("Goal state found.")
            print("Final state: ")
            print_state(goal_state)
            break


hill_climbing(start_state)
