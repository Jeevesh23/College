import numpy as np
import matplotlib.pyplot as plt
# Function to calculate the factorial of a number
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

# Function to calculate the value of the Taylor Series at a given x
def taylor_series(x):
    n_terms = 5 # Number of terms in the Taylor Series
    result = 0
    for n in range(n_terms):
        term = (-1) ** n * x ** (2 * n) / factorial(2 * n)
        result += term
    return result

# Generate x values from -10 to 10
x_values = np.linspace(-10, 10, 100)

# Calculate y values using the Taylor Series expansion
y_values = np.array([taylor_series(x) for x in x_values])

# Plot the Taylor Series
plt.plot(x_values, y_values, label="Taylor Series (5 terms)")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.title("Taylor Series Expansion")
plt.legend()
plt.grid(True)
plt.show()