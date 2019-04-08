import matplotlib.pyplot as plt
import seaborn as sns; sns.set(color_codes=True)
from pandas import read_csv as read

path = "wh.csv"
rows = 1000

data = read(path, nrows=rows, delimiter=",")

# sns.lmplot(x="Humidity", y="Temperature (C)", data=data)
# plt.savefig("Humidtity.png")

# sns.lmplot(x="Apparent Temperature (C)", y="Temperature (C)", data=data)
# plt.savefig("Apparent Temperature (C).png")

# sns.lmplot(x="Wind Speed (km/h)", y="Temperature (C)", data=data)
# plt.savefig("Wind Speed (kmh).png")

# sns.lmplot(x="Wind Bearing (degrees)", y="Temperature (C)", data=data)
# plt.savefig("Wind Bearing (degrees).png")

# sns.lmplot(x="Visibility (km)", y="Temperature (C)", data=data)
# plt.savefig("Visibility (km).png")

# sns.lmplot(x="Loud Cover", y="Temperature (C)", data=data)
# plt.savefig("Loud Cover.png")

# sns.lmplot(x="Pressure (millibars)", y="Temperature (C)", data=data)
# plt.savefig("Pressure (millibars).png")

# sns.distplot(data['Temperature (C)'])
# plt.savefig("distTemp.png")

sns.pairplot(data, kind='reg')
plt.savefig("pairPlot3.png")