import math
# Take a 4x4 matrix as input from the user
A = []
print("Enter the elements of the 4x4 matrix:")
for i in range(4):
    row = []
    for j in range(4):
        element = float(input("Enter the value for A[{}][{}]: ".format(i+1, j+1)))
        row.append(element)
    A.append(row)
# Ini􀆟alize an empty 4x4 matrix L
L = [[0] * 4 for _ in range(4)]
# Perform Cholesky Decomposi􀆟on
for i in range(len(A)):
    for j in range(i+1):
        if i == j:
            sum_sq = sum(L[i][k] ** 2 for k in range(j))
            L[i][j] = math.sqrt(A[i][i] - sum_sq)
        else:
            sum_prod = sum(L[i][k] * L[j][k] for k in range(j))
            if L[j][j] != 0:
                L[i][j] = (A[i][j] - sum_prod) / L[j][j]
            else:
                L[i][j] = 0
# Print the Cholesky Decomposi􀆟on
print("Cholesky Decomposi􀆟on of A:")
for row in L:
    print(row)