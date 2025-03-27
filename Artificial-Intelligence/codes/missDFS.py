f = 0
visited = []


def check(x, y, n):
    if x < 0 or y < 0 or x > n or y > n:
        return False

    if (x >= y or x == 0 or y == 0) and (
        (n - x) >= (n - y) or (n - x) == 0 or (n - y) == 0
    ):
        return True
    else:
        return False


def misscan(i, j, boat_capacity, bank, path, n):
    global f

    if (i, j, bank) in visited:
        return

    path.append((i, j, bank))

    # end state
    if (i, j, bank) == (0, 0, "R"):
        f = 1
        print("Solution:")
        print(*path, sep=" ➤ ")
        print()
        path.pop()
        return

    visited.append((i, j, bank))

    if bank == "L":
        # send missionaries and cannibals in all possible combinations
        for miss in range(boat_capacity + 1):
            for cann in range(boat_capacity - miss + 1):
                if miss + cann > 0 and miss + cann <= boat_capacity:
                    if check(i - miss, j - cann, n):
                        misscan(i - miss, j - cann, boat_capacity, "R", path, n)
    else:
        # send missionaries and cannibals in all possible combinations
        for miss in range(boat_capacity + 1):
            for cann in range(boat_capacity - miss + 1):
                if miss + cann > 0 and miss + cann <= boat_capacity:
                    if check(i + miss, j + cann, n):
                        misscan(i + miss, j + cann, boat_capacity, "L", path, n)

    path.pop()


def validate_input(missionaries, cannibals, boat_capacity):
    if cannibals > missionaries > 0 or missionaries <= 0 or cannibals <= 0 or boat_capacity <= 0:
        print("Invalid input: Number of cannibals cannot exceed missionaries, and all inputs must be positive.")
        return False
    return True


def get_input():
    missionaries = int(input("Enter number of missionaries: "))
    cannibals = int(input("Enter number of cannibals: "))
    boat_capacity = int(input("Enter boat capacity: "))
    return missionaries, cannibals, boat_capacity


missionaries, cannibals, boat_capacity = get_input()

if not validate_input(missionaries, cannibals, boat_capacity):
    exit()

p = []
n = max(missionaries, cannibals)
misscan(missionaries, cannibals, boat_capacity, "L", p, n)

if f == 0:
    print("No solution could be found.")