import numpy as np
import scipy.linalg as la
import pprint
# Take a 4x4 matrix as input from the user
A = np.zeros((4, 4))
for i in range(4):
    for j in range(4):
        A[i, j] = float(input("Enter the value for A[{}][{}]: ".format(i+1, j+1)))
try:
    # Find Cholesky Decomposi􀆟on
    L = la.cholesky(A, lower=True)
    # Display Cholesky Decomposi􀆟on using pprint
    print("Cholesky Decomposi􀆟on of A:")
    pp = pprint.PreyPrinter(indent=4)
    pp.pprint(L)
except la.LinAlgError:
    print("Cholesky decomposi􀆟on cannot be performed. The matrix is not posi􀆟ve definite.")