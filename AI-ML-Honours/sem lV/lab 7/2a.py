import pandas as pd
import matplotlib.pyplot as plt
# Load the dataset
df = pd.read_csv('C:/Users/pedne/Downloads/archive/penguins_size.csv')
plt.sca􀆩er(df['culmen_length_mm'], df['flipper_length_mm'])
plt.xlabel('Culmen Length (mm)')
plt.ylabel('Flipper Length (mm)')
plt.􀆟tle('Rela􀆟onship between Flipper Length and Culmen Length')
plt.show()