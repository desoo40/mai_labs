import numpy as np
import pandas as pd
from pandas import read_csv as read
import matplotlib.pyplot as plt
import seaborn as sns; sns.set(color_codes=True)

path = "wh1.csv"
rows = 10000000

data = read(path, delimiter=",", nrows=rows)

y = data['Temperature (C)'].values
data.drop('Temperature (C)', axis=1, inplace=True)
data.drop('Formatted Date', axis=1, inplace=True)
data.drop('Cont', axis=1, inplace=True)
# data.drop('Apparent Temperature (C)', axis=1, inplace=True)

from sklearn.preprocessing import LabelEncoder

le = LabelEncoder()
data['Summary'] = le.fit_transform(data['Summary'])
data['Precip Type'] = le.fit_transform(data['Precip Type'])
data['Daily Summary'] = le.fit_transform(data['Daily Summary'])

X = data.values

from sklearn.model_selection import train_test_split as train

X_train, X_test, y_train, y_test = train(X, y, test_size=0.3, shuffle=False)

# print(X_train[0])
# print(y_train[0])
# print(X_test[0])
# print(y_test[0])
# print(len(y_test))

from sklearn import linear_model

reg = linear_model.LinearRegression()
# reg = linear_model.BayesianRidge()
# reg = linear_model.SGDRegressor()
# reg = linear_model.Lars()
# reg = linear_model.LinearRegression()
reg.fit(X_train, y_train)

expected = y_test
predicted = reg.predict(X_test)


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

# lol = []

# for i in range(0, len(expected)):
#     tmp = expected[i] - np.dot(X_test[i], reg.coef_[0]) - reg.intercept_
#     lol.append(tmp)

resid = expected - predicted

import statsmodels.api as sm
dw = sm.stats.stattools.durbin_watson(resid)

df = pd.DataFrame()
df['Exp'] = expected
df['pre'] = predicted
df['res'] = resid
df.to_csv('ep.csv', index=False)



# sns.distplot(df['Err'])
# plt.savefig("err.png")