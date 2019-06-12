import numpy as np
np.random.seed(42)
def my_func(x):
    return (x ** 2 + 1 + np.exp(x)) / (np.sin(x) + np.cos(x) + np.tan(x))
def integrate(x1, x2, n, func=my_func):
    bag = []
    for i in range(n):
        x = np.random.uniform(x1, x2, 1)
        bag.append(func(x))

    return ((x2 - x1) * np.mean(bag))

if __name__ == '__main__':
    a = np.pi / 2.5
    b = np.pi / 10

    for i in [10, 100, 1000, 10000, 100000]:
        ans = integrate(a, b, i)
        print("Количество испытаний - {}, \n "
              "Среднее значение интеграла = {}\n".format(i, ans))
