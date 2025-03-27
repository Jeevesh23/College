import pandas as pd
import matplotlib.pyplot as plt
# Load the dataset
df = pd.read_csv('C:/Users/pedne/Downloads/archive/penguins_size.csv')
plt.hist(df['culmen_length_mm'], bins=10)
plt.xlabel('Culmen Length (mm)')
plt.ylabel('Count')
plt.􀆟tle('Histogram of Culmen Length')
plt.show()