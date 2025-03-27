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

def bfs():
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
bfs()
