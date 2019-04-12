import numpy as np
from pandas import read_csv as read

path = "wh.csv"
rows = 10

dataX = read(path, delimiter=",", usecols=[1,2,4,5,6,7,8,9,10,11])
dataY = read(path, delimiter=",", usecols=[3])

X = dataX.values
y = dataY.values

from sklearn.preprocessing import LabelEncoder

le = LabelEncoder()
X[:, 0] = le.fit_transform(X[:, 0])
X[:, 1] = le.fit_transform(X[:, 1])
X[:, 9] = le.fit_transform(X[:, 9])

from sklearn.model_selection import train_test_split as train

X_train, X_test, y_train, y_test = train(X, y, test_size=0.3, shuffle=False)

# print(X_train[0])
# print(y_train[0])
# print(X_test[0])
# print(y_test[0])
# print(len(y_test))

from sklearn.linear_model import LinearRegression

reg = LinearRegression()
reg.fit(X_train, y_train)

expected = y_test
predicted = reg.predict(X_test)

import matplotlib.pyplot as plt

# plt.scatter(expected,predicted)
# plt.savefig("expPredwithAtemp.png")

print('B0: ', reg.intercept_)
print('Coefficients: \n', reg.coef_)
print('Variance score: ', reg.score(X, y))

from sklearn import metrics
print('MAE: ', metrics.mean_absolute_error(expected, predicted))
print('MSE: ', metrics.mean_squared_error(expected, predicted))
print('RMSE: ', np.sqrt(metrics.mean_squared_error(expected, predicted)))
print('EVS: ', metrics.explained_variance_score(expected, predicted))
print('R2: ', metrics.r2_score(expected, predicted))

lol = []

for i in range(0, len(expected)):
    tmp = expected[i] - np.dot(X_test[i], reg.coef_[0]) - reg.intercept_
    lol.append(tmp)

err = expected - predicted
dt = np.concatenate([expected, predicted, err, lol], axis=1)

import pandas as pd
df = pd.DataFrame(dt, columns = ['Expected', 'Predicted', 'Err', 'Residues'])
df.to_csv('ep.csv', index=False)

# import seaborn as sns; sns.set(color_codes=True)
# sns.distplot(df['Err'])
# plt.savefig("err.png")