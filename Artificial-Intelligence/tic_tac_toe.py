from copy import deepcopy

def heuristic(state):
    for row in range(3):
        if state[row][0] == state[row][1] and state[row][1] == state[row][2]:
            if state[row][0] == "X":
                return 100
            elif state[row][0] == "O":
                return -100
    for column in range(3):
        if (
            state[0][column] == state[1][column]
            and state[1][column] == state[2][column]
        ):
            if state[0][column] == "X":
                return 100
            elif state[0][column] == "O":
                return -100
    if (state[0][0] == state[1][1] and state[1][1] == state[2][2]) or (
        state[0][2] == state[1][1] and state[1][1] == state[2][0]
    ):
        if state[1][1] == "X":
            return 100
        elif state[1][1] == "O":
            return -100
    return 0

def genChildren(state, maxPlayer):
    children = []
    for i in range(3):
        for j in range(3):
            tempState = deepcopy(state)
            if tempState[i][j] == "_":
                if maxPlayer:
                    tempState[i][j] = "X"
                else:
                    tempState[i][j] = "O"
                temptempState = deepcopy(tempState)             
                children.append(temptempState)
                tempState[i][j] = "_"
    return children

def minimax(state, maxPlayer):
    heuristicValue = heuristic(state)
    if abs(heuristicValue) == 100:
        return heuristicValue
    children = []
    heuristics = []
    if maxPlayer:
        children = genChildren(state, maxPlayer)
        if len(children) == 0:
            return heuristic(state)
        for child in children:
            heuristicValue = minimax(child, False)
            heuristics.append(heuristicValue)

        max_val = -99999
        for i in range(len(children)):
            if heuristics[i] > max_val:
                max_val = heuristics[i]
        return max_val
    else:
        children = genChildren(state, maxPlayer)
        if len(children) == 0:
            return heuristic(state)
        for child in children:
            heuristicValue = minimax(child, True)
            heuristics.append(heuristicValue)
        min_val = 99999
        for i in range(len(children)):
            if heuristics[i] < min_val:
                min_val = heuristics[i]
        return min_val

def movesLeft(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == "_":
                return True

def playGame():
    print("You will play as 'X', against the AI. Good luck.....\n")
    state = [["_" for i in range(3)] for j in range(3)]
    print(*state, sep="\n")
    global drawFlag
    while movesLeft(state):
        print("Enter the matrix coordinates of where you want to play:")
        x, y = input().split()
        x = int(x)
        y = int(y)
        if x not in range(3) and y not in range(3):
            print("Invalid coordinates, enter again")
            print()
            continue
        if state[x][y] != "_":
            print("Oi, no cheating, you can't overwrite a move.... enter again")
            print()
            continue
        state[x][y] = "X"
        print("Your move: ")
        print(*state, sep="\n")
        if heuristic(state) == 100:
            print("YAYY, you won and beat the AI...")
            print("Exiting game....")
            drawFlag = False
            return
        moves = []
        heuristics = []
        moves = genChildren(state, False)

        for move in moves:
            heuristics.append(minimax(move, True))

        min_val = 99999
        for i in range(len(moves)):
            if heuristics[i] < min_val:
                min_val = heuristics[i]
                state = moves[i]

        print("AI move: ")
        print(*state, sep="\n")

        if heuristic(state) == -100:
            print("Oh no, the AI beat you...")
            print("Exiting game....")
            drawFlag = False
            return

drawFlag = True

if __name__ == "__main__":
    playGame()

    if drawFlag:
        print("Oh! it's a draw...")
        print()
