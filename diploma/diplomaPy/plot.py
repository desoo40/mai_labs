import matplotlib.pyplot as plt
import seaborn as sns; sns.set(color_codes=True)
from pandas import read_csv as read

path = "data.csv"

data = read(path, delimiter=",")

data.hist('amount', bins=10000)

# sns.distplot(data['amount'])
plt.savefig("plots\\distAmount.png")