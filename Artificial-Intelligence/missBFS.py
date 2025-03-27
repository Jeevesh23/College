# from collections import deque

# visited = set()


# def check(x, y):
#     if x < 0 or y < 0 or x > n or y > n:
#         return False

#     if (x >= y or x == 0 or y == 0) and (
#         (n - x) >= (n - y) or (n - x) == 0 or (n - y) == 0
#     ):
#         return True
#     else:
#         return False


# def misscan(i, j, bank):
#     global f

#     queue = deque([(i, j, bank, [])])
#     solutions = []

#     while queue:
#         i, j, bank, path = queue.popleft()  # dequeue a state

#         if (i, j, bank) in visited:
#             continue

#         path.append((i, j, bank))

#         # end state
#         if (i, j, bank) == (0, 0, "R"):
#             solutions.append(path)
#             continue  # we continue from here because if we don’t then we will add the final state in vis and never be able to go to it again

#         visited.add((i, j, bank))

#         if bank == "L":
#             # send 1 miss
#             if check(i - 1, j):
#                 queue.append((i - 1, j, "R", path[:]))

#             # send 2 miss
#             if check(i - 2, j):
#                 queue.append((i - 2, j, "R", path[:]))

#             # send 1 cann
#             if check(i, j - 1):
#                 queue.append((i, j - 1, "R", path[:]))

#             # send 2 cann
#             if check(i, j - 2):
#                 queue.append((i, j - 2, "R", path[:]))

#             # send 1 miss 1 cann
#             if check(i - 1, j - 1):
#                 queue.append((i - 1, j - 1, "R", path[:]))
#         else:
#             # send 1 miss
#             if check(i + 1, j):
#                 queue.append((i + 1, j, "L", path[:]))

#             # send 2 miss
#             if check(i + 2, j):
#                 queue.append((i + 2, j, "L", path[:]))

#             # send 1 cann
#             if check(i, j + 1):
#                 queue.append((i, j + 1, "L", path[:]))

#             # send 2 cann
#             if check(i, j + 2):
#                 queue.append((i, j + 2, "L", path[:]))

#             # send 1 miss 1 cann
#             if check(i + 1, j + 1):
#                 queue.append((i + 1, j + 1, "L", path[:]))

#     return solutions


# n = int(input("Enter number of miss and can: "))
# solutions = misscan(n, n, "L")

# if not solutions:
#     print("no solution could be found")
# else:
#     print("Solutions:")
#     for solution in solutions:
#         print("Solution path:")
#         print(*solution, sep=" ➤ ")
#         print()


from collections import deque

visited = set()


def check(x, y, n):
    if x < 0 or y < 0 or x > n or y > n:
        return False

    if (x >= y or x == 0 or y == 0) and (
        (n - x) >= (n - y) or (n - x) == 0 or (n - y) == 0
    ):
        return True
    else:
        return False


def misscan(m, c, b, n):
    global f

    queue = deque([(m, c, b, [])])
    solutions = []

    while queue:
        m, c, b, path = queue.popleft()  # dequeue a state

        if (m, c, b) in visited:
            continue

        path.append((m, c, b))

        # end state
        if (m, c, b) == (0, 0, "R"):
            solutions.append(path)
            continue  # we continue from here because if we don’t then we will add the final state in vis and never be able to go to it again

        visited.add((m, c, b))

        if b == "L":
            # send 1 miss
            if check(m - 1, c, n):
                queue.append((m - 1, c, "R", path[:]))

            # send 2 miss
            if check(m - 2, c, n):
                queue.append((m - 2, c, "R", path[:]))

            # send 1 cann
            if check(m, c - 1, n):
                queue.append((m, c - 1, "R", path[:]))

            # send 2 cann
            if check(m, c - 2, n):
                queue.append((m, c - 2, "R", path[:]))

            # send 1 miss 1 cann
            if check(m - 1, c - 1, n):
                queue.append((m - 1, c - 1, "R", path[:]))
        else:
            # send 1 miss
            if check(m + 1, c, n):
                queue.append((m + 1, c, "L", path[:]))

            # send 2 miss
            if check(m + 2, c, n):
                queue.append((m + 2, c, "L", path[:]))

            # send 1 cann
            if check(m, c + 1, n):
                queue.append((m, c + 1, "L", path[:]))

            # send 2 cann
            if check(m, c + 2, n):
                queue.append((m, c + 2, "L", path[:]))

            # send 1 miss 1 cann
            if check(m + 1, c + 1, n):
                queue.append((m + 1, c + 1, "L", path[:]))

    return solutions


def input_validity(m, c):
    if c > m > 0 or m == 0:
        return False
    return True


while True:
    num_miss = int(input("Enter number of missionaries: "))
    num_cann = int(input("Enter number of cannibals: "))
    boat_capacity = int(input("Enter the boat capacity: "))

    if not input_validity(num_miss, num_cann):
        print("Invalid input: Number of cannibals cannot exceed the number of missionaries.")
        continue

    if num_miss < boat_capacity and num_cann < boat_capacity:
        print("No solution possible. Both missionaries and cannibals are less than boat capacity.")
        continue

    solutions = misscan(num_miss, num_cann, "L", max(num_miss, num_cann))

    if not solutions:
        print("No solution could be found.")
    else:
        print("Solutions:")
        for solution in solutions:
            print("Solution path:")
            print(*solution, sep=" ➤ ")
            print()
    break
