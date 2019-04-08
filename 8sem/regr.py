import numpy as np
from pandas import read_csv as read

path = "wh.csv"
rows = 100
data = read(path, delimiter=",")

print(len(data))

X = data.values[:, 0:10]
y = data.values[:, 11]
# y=y.astype('int') # не совсем понял, почему https://stackoverflow.com/questions/45346550/valueerror-unknown-label-type-unknown

from sklearn.preprocessing import LabelEncoder

le = LabelEncoder()
X[:, 0] = le.fit_transform(X[:, 0])
X[:, 1] = le.fit_transform(X[:, 1])
X[:, 2] = le.fit_transform(X[:, 2])

y = le.fit_transform(y)

from sklearn.model_selection import train_test_split as train

X_train, X_test, y_train, y_test = train(X, y)

from sklearn.linear_model import LinearRegression
reg = LinearRegression()

reg.fit(X_train, y_train)

expected = y_test
predicted = reg.predict(X_test)

print(reg.score(X, y), reg.intercept_, reg.coef_)