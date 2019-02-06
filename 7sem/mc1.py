import numpy as np
import math
from scipy.stats import truncnorm
from time import time
from tabulate import tabulate

def simpson(interval, f, h):
    a, b = interval
    n = int((b - a) / h + 1)

    first_part = 4 * np.sum([f(a + i * h) for i in range(1, n, 2)])
    second_part = 2 * np.sum([f(a + i * h) for i in range(2, n - 1, 2)])
    integral = h * (f(a) + first_part + second_part + f(b)) / 3

    return integral


def normal_rand_generator(lower, upper, size):
    res = [truncnorm.rvs(a, b) for a, b in zip(lower, upper)]

    return res


def monte_carlo(intervals, f, experiments_amount, random_generator=np.random.uniform):
    size = len(intervals)
    lower, upper = zip(*intervals)
    volume = np.prod([b - a for a, b in intervals])
    integral = volume * np.sum([f(random_generator(lower, upper, size)) for _ in range(experiments_amount)]) / experiments_amount

    return integral


def calc_int(f, interval):
    a, b = interval

    return f(b) - f(a)


def bench_methods(funcs, monte_funcs, anal_funcs, intervals, h, experiments_amount):
    quad_times = []
    quad_res = []
    monte_times = []
    monte_res = []
    norm_times = []
    norm_res = []
    anal_res = []

    for i in range(len(intervals)):
        j = i + 1
        start = time()
        quad_ints = np.prod([simpson(interval, func, h) for func, interval in zip(funcs[:j], intervals[:j])])
        end = time()
        quad_res.append("%.4f" % quad_ints)
        quad_times.append("%.4f" % (end - start))


        start = time()
        monte_int = monte_carlo(intervals[:j], monte_funcs[i], experiments_amount)
        end = time()
        monte_res.append("%.4f" % monte_int)
        monte_times.append("%.4f" % (end - start))

        start = time()
        monte_int = monte_carlo(intervals[:j], monte_funcs[i], experiments_amount, normal_rand_generator)
        end = time()
        norm_res.append("%.4f" % monte_int)
        norm_times.append("%.4f" % (end - start))

        anal_res.append("%.4f" % np.prod([calc_int(func, interval) for func, interval in zip(anal_funcs[:j], intervals[:j])]))

    headers = ("Arity", "Monte-Carlo with uniform", "Monte-Carlo with normal", "Simpson", "Analytical")
    content = zip(list(range(1, len(intervals) + 1)), list(zip(monte_res, monte_times)), list(zip(norm_res, norm_times)), list(zip(quad_res, quad_times)), anal_res)

    table = tabulate(list(content), headers, tablefmt="fancy_grid")
    print(f'Intervals = {intervals}')
    print(f'Monte-Carlo experiments {experiments_amount}')
    print(f'Step size = {h}')
    print(table)

def main():
    funcs = [lambda x: 1 / (x + np.cbrt(x)), \
             lambda x: 1 / math.sqrt(x ** 2 + 3.22), \
             lambda x: math.sin(x) ** 3, \
             lambda x: 1 / (1 + math.sin(x)), \
             lambda x: math.log(x + 2) / x, \
             lambda x: math.log(x) / (x ** 2)
    ]
    monte_funcs = [funcs[0], \
                   lambda x: funcs[0](x[0]) * funcs[1](x[1]), \
                   lambda x: funcs[0](x[0]) * funcs[1](x[1]) * funcs[2](x[2]), \
                   lambda x: funcs[0](x[0]) * funcs[1](x[1]) * funcs[2](x[2]) * funcs[3](x[3]), \
                   lambda x: funcs[0](x[0]) * funcs[1](x[1]) * funcs[2](x[2]) * funcs[3](x[3]) * funcs[4](x[4]), \
                   lambda x: funcs[0](x[0]) * funcs[1](x[1]) * funcs[2](x[2]) * funcs[3](x[3]) * funcs[4](x[4]) * funcs[5](x[5])
    ]
    anal_funcs = [lambda x: 3 * math.log(np.cbrt(x ** 2) + 1) / 2,\
                  lambda x: math.log(np.abs(x + math.sqrt(x ** 2 + 3.22))),\
                  lambda x: (math.cos(3 * x) - 9 *math.cos(x)) / 12,\
                  lambda x: -2 / (math.tan(x / 2) + 1),
                  lambda x: 2 * 0.648437 if x == 2 else 0.648437,
                  lambda x: -(math.log(x) + 1) / x
        ]
    intervals = [(-3, -1), (1, 3), (3, 5), (5, 7), (1.2, 2), (14, 88)]

    print("Format in methods is (value, time in seconds)")

    for h, experiments_amount in [(0.1, 100), (0.01, 1000)]:
        bench_methods(funcs, monte_funcs, anal_funcs, intervals, h, experiments_amount)

    
main()