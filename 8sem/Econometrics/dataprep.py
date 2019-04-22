import numpy as np
import pandas as pd
from pandas import read_csv as read

path = "wh.csv"
data = read(path, delimiter=",")
lines = data['Formatted Date'].values

years = []
months = []
days = []
hours = []
conti = []

for line in lines: 
    tmp = line.split()
    tmp1 = tmp[0].split('-')
    tmp2 = tmp[1].split(':')

    year = tmp1[0]
    month = tmp1[1]
    day = tmp1[2]
    hour = tmp2[0]
    
    years.append(year)
    months.append(month)
    days.append(day)
    hours.append(hour)
    conti.append(int(hour) + int(day) * 24 + int(month) * 30 * 24 + (int(year)-2000) * 12 * 30 * 24)

print(years)
print(months)
print(days)
print(hours)

data['Year'] = years
data['Month'] = months
data['Day'] = days
data['Hour'] = hours
data['Cont'] = conti
print(data)
data.to_csv('wh1.csv', index=False)