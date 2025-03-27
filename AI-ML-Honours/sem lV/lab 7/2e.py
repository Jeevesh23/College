import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
# Load the dataset
df = pd.read_csv('C:/Users/pedne/Downloads/archive/penguins_size.csv')
sns.pairplot(data=df, hue='species')
plt.􀆟tle('Pairwise Visualiza􀆟on of A􀆩ributes')
plt.show()