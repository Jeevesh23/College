import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
# Load the dataset
df = pd.read_csv('C:/Users/pedne/Downloads/archive/penguins_size.csv')
sns.barplot(data=df, x='sex', y='body_mass_g')
plt.xlabel('Sex')
plt.ylabel('Body Mass (g)')
plt.􀆟tle('Body Mass of Penguin Species by Sex')
plt.show()