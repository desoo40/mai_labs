import matplotlib.pyplot as plt
from scipy.interpolate import make_interp_spline, BSpline
import numpy as np

T = np.array([4,3,3,9,4,2,3,10,3,0,8,6,5,0,4,0,3,7,3,2,4,2,3])
xnew = np.linspace(T.min(),T.max(),300) #300 represents number of points to make between T.min and T.max

spl = make_interp_spline(T, power, k=3) #BSpline object
power_smooth = spl(xnew)

plt.plot(xnew,power_smooth)
plt.show()