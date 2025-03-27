import math
# Declare a 4x4 matrix
A = [[18, 22, 54, 42],
[22, 70, 86, 62],
[54, 86, 174, 134],
[42, 62, 134, 106]]
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
            L[i][j] = (A[i][j] - sum_prod) / L[j][j]
# Print the Cholesky Decomposi􀆟on
print("Cholesky Decomposi􀆟on of A:")
for row in L:
    print(row)