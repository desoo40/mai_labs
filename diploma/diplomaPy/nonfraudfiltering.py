import numpy as np
import random
from pandas import read_csv as read

path = "data.csv"
data = read(path, delimiter=",", nrows=7000000)

X = data.values
drops = list()
for i in range(0, len(X)):
    if (i % 500000 == 0):
        print(i)
    if X[i][9] == 0 and random.randint(0, 60) < 60:
        drops.append(i)

new = data.drop(drops)
new.to_csv("filtData.csv", index=False)