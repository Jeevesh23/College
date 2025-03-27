import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
# Load the dataset
df = pd.read_csv('C:/Users/pedne/Downloads/archive/penguins_size.csv')
sns.boxplot(data=df, x='species', y='flipper_length_mm')
plt.xlabel('Species')
plt.ylabel('Flipper Length (mm)')
plt.􀆟tle('Distribu􀆟on of Flipper Length by Species')
plt.show()