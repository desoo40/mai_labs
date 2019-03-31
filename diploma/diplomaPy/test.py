import numpy as np
from pandas import read_csv as read

path = "predict.csv"
data = read(path, delimiter=";", header="None")
# print(data.head())

X = data.values[::, 0:6]
y = data.values[::, 7]
