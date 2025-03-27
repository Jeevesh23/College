import math
import pprint
A1 = [[4, 2], [2, 5]]
L1 = [[math.sqrt(A1[0][0]), 0], [A1[1][0] / math.sqrt(A1[0][0]), math.sqrt(A1[1][1] - (A1[1][0]
** 2) / A1[0][0])]]
print("Cholesky Decomposition of 2x2 Matrix:")
pprint.pprint(L1)