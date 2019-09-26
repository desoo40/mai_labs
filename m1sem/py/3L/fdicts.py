class FDict():
    def __init__(self):
        self.f_to_c_dct = {}
        self.c_to_f_dct = {}

    # добавляет функцию с кодом
    def add(self, code, func):
        self.f_to_c_dct[func] = code
        self.c_to_f_dct[code] = func
    
    # удаляет функцию по коду
    def remove(self, code):
        func = self.c_to_f_dct[code]
        self.f_to_c_dct.pop(func)
        self.c_to_f_dct.pop(code)

    # выполняет функцию с аргументом
    def execute(self, code, arg):
        return self.c_to_f_dct[code](arg)
    
    # возвращает функцию по коду
    def get_func(self, code):
        pass
    
    # получает 2*N аргументов (код, значение, код, значение ..) и возвращает кортеж из значений
    def execute_many(self, *args):
        return tuple([1] * int(len(args)/2) )


import math
from math import sin, cos

x = math.pi / 3

func_dict = FDict()
func_dict.add('sin', math.sin)
func_dict.add('cos', math.cos)

y1 = func_dict.execute('sin', x)
y2 = func_dict.execute('cos', x)

print("1. sin({0:.4f})={1:.4f}, cos({0:.4f})={2:.4f}".format(x, y1, y2))

# y1, y2 = func_dict.execute_many('sin', x*2, 'cos', x*3)
# print("2. sin({0:4f})={1:4f}, cos({0:4f})={2:4f}".format(x, y1, y2))