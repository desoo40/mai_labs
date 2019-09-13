# To add a new cell, type '#%%'
# To add a new markdown cell, type '#%% [markdown]'
#%%
from IPython import get_ipython

#%% [markdown]
# <center>
# 
# # Курс "Основы Python для анализа данных"
# 
# ## Артамонов Игорь Михайлович
# ## Факультет "Прикладная математика" МАИ
# 
# ### Занятие № 2.  Основные типы данных. Обработка исключений.
# 
# </center>
# 
#%% [markdown]
# ## Общение / вопросы по курсу
# 
# Платформа для групповой работы Atlassian Confluence факультета "Прикладная математика"
# 
# https://mai.moscow/display/PYTML
#%% [markdown]
# * <b>Занятие 2. Основные типы данных. Обработка исключений.</b>
#      * Последовательности: строка, список, кортеж, множество
#      * Словарь
#      * Стеки, очередь, дерево
#      * Случайные величины
#      * Исключения и их обработка
#%% [markdown]
# ## virtualenv + Jupyter notebook
#%% [markdown]
# ```
# <Ctrl> + <Alt> + T - новое окно терминала
# ```
#%% [markdown]
# ```
# $ conda -V
# 
# $ conda update conda
# 
# $ conda search "^python$"
# 
# $ conda create -n yourenvname python=x.x anaconda
# 
# $ source activate yourenvname
# 
# $ jupyter notebook
# 
# $ conda install -n yourenvname [package]
# ```
#%% [markdown]
# # ВАЖНО!
#%% [markdown]
# * курс построен как "__слойка__"
# * плохое освоение модуля __сильно__ затрудняет освоение следующего модуля
# * возвратов и повторов __мало__ ...
#%% [markdown]
# # Общее
#%% [markdown]
# * Python имеет много __встроенных__ сложных структур данных
# * Наиболее часто используемыми являются:
#    - строка
#    - список
#    - кортеж
#    - словарь
#    - множество
# * В большинстве случаев, код для встроенных структур написан на языке низкого уровня и хорошо оптимизирован
# * __ВЫВОД № 1__: если Вам требуется какая-то структура, то:
#    - поищите уже реализованную структуру (стек, очередь, ...)
#    - сводите её к одной из типовых
#    - старайтесь максимально использовать встроенные функции типовых структур
# * __ВЫВОД № 2__:
#    - имеет смысл __полностью__ просматривать руководство по нужному классу

#%%
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import scipy as sc
get_ipython().run_line_magic('matplotlib', 'inline')

#%% [markdown]
# ## Основные сложные структуры данных
#%% [markdown]
# * связанные списки (linked list) - односторонние и двусторонние
# * стек (stack)
# * очередь (queue)
# * хэш-таблица (hash table)
# * двоичное дерево (binary tree)
#%% [markdown]
# # Рекурсия
#%% [markdown]
# Рекурсия - обращение функции __к самой себе__

#%%
def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)


#%%
factorial(10)

#%% [markdown]
# ### Сохранение значения

#%%
def sum_accum(current, accum, n):
    # Финальное состояние
    if current == n:
        return accum

    # Рекурсия
    else:
        return sum_accum(current + 1, accum + current, n)


#%%
sum_accum(0, 0, 5)

#%% [markdown]
# ### Когда рекурсия полезна?
#%% [markdown]
# * большая читаемость кода
# * работа с неизменяемыми значениями
# * работа с "естественно" рекурсивными структурами (деревья, графы)
#%% [markdown]
# ### Ограничения
#%% [markdown]
# * рекурсия менее эффективная, чем итрации
# * ограничена глубина стека

#%%
import sys
sys.getrecursionlimit()

#%% [markdown]
# ### <font color=red>Задание</font>
#%% [markdown]
# Вычислите рекурсивно __$e^x$__ по $n$ первым элементам ряда:
#%% [markdown]
# $$e(x) = \sum_{i=0}^{n} \frac{x^n}{n!}$$

#%%
import math

def my_exp(x, n):
    # Ваш код
    return 1 if n == 0 else  x**n / factorial(n) + my_exp(x, n -1 )
    #return n == 0 ? 1 : x**n / factorial(n) + my_exp()


#%%
print("{:.8f}".format(my_exp(1, 50)))

#%% [markdown]
# ## Строка
#%% [markdown]
# * могут ограничиваться либо одинарными __'< str >'__ , либо двойными __"< str >"__, либо тройными двойными ___"""< multiline str >"""___ кавычками
# * в целом, аналогична списку из символов
# * может быть преобразована в список командой __list()__
# * существуют команды, типичные для обработки строк в других языках

#%%
s = 'Ехал Грека через реку, видит грека - в реке рак'


#%%
'abc' == "abc"


#%%
'abc' > "rbc"


#%%
long_str = """
this is
a very
long 
string
"""


#%%
long_str, len(long_str)


#%%
s = 'Ехал Грека через реку, видит грека - в реке рак'


#%%
s.startswith( 'река' ), s.startswith( 'Ехал' )


#%%
print(s.startswith( 'река', 6))


#%%
print(s.startswith( 'река', 6, 9))


#%%
print(s.endswith( 'рак'))


#%%
s.count('рек')


#%%
s.find('через')


#%%
s_enc = s.encode('cp1252', errors='ignore')
s_enc


#%%
s = "ascii"


#%%
s.join(','), s.join('::::')


#%%
long_str.split('\n')

#%% [markdown]
# ### Специальные символы
#%% [markdown]
# * \n - перевод строки
# * \r - возврат каретки
# * \t - табуляция
# * \xNN - символ в 16-ричной нотации
# * \ - символ экранирования (\\n)

#%%
print('a' + '\n' + 'b')


#%%
print('a' + '\r' + 'b')


#%%
print('a' + '\t' + 'b')


#%%
print('a' + '\\n' + 'b')

#%% [markdown]
# ### Индексирование строк и списков
#%% [markdown]
# * индекс размещается в квадратных скобках __\[ \]__
# * начинается с 0
# * отрицательный индекс __n__ означает __len(s) - n__ => -1 __исключает__ последний символ
# * можно указывать диапазон через двоеточие __:__
# * отсутствующий индекс перед двоеточиием означает __"с начала"__, после - __"до последнего символа включительно"__
# * можно добавить второе двоеточие, которое означает __"шаг"__

#%%
s = 'Большая длинная тестовая строка'


#%%
len(s)


#%%
s[31]


#%%
s[16:-1], s[16:len(s)], s[-1]


#%%
s = '0123456789'
s[0:-1:2]

#%% [markdown]
# ### <font color=red>Задание</font>
#%% [markdown]
# * пользуясь __только__ индексом, выведите строку в обратном порядке

#%%
s[len(s):0:-1]

#%% [markdown]
# ## Операции над строками

#%%
print(var_dic_list())


#%%
s = 'abc' + ' - ' + 'cde'
s


#%%
s = (s + '? ') * 3
s


#%%
to_find = 'abc'
if to_find in s:
    s1 = 'Нашли <' + to_find + '> в строке <' + s + '>'
    print(s1)

#%% [markdown]
# ### Преобразование регистра

#%%
s1.upper(), s1.lower()


#%%
s1.find('abc')


#%%
s1.find('abs')


#%%
s1.count('abc'), s1[8:].count('abc')


#%%
s = '  qwerty  '
s_left = '<' + s.lstrip() + '>'
s_right = '<' + s.rstrip() + '>'
s_both = '<' + s.strip() + '>'
print(s_left, s_right, s_both)


#%%
s1.replace('abc', 'ABC')


#%%
s1


#%%
s1.split('?')

#%% [markdown]
# ### Форматирование
#%% [markdown]
# * __% форматирование__
#     * %d - целые
#     * %s - строки
#     * %f - с плавающей точкой

#%%
print('Это строка <%s>, это целое число <%05d>, а это число с плавающей точкой <%03d>' % ('ABC', 234, 3.1415926))


#%%
print(s_fmt1)

#%% [markdown]
# * Форматирование классом __formatter__

#%%
fmt = 'Это строка <{0:s}>, это целое число <{1:05d}>, это число с плавающей точкой <{2:3.4f}>, а это снова строка {0}'
print(fmt.format('ABC', 234, 3.1415926) )


#%%
fmt = 'Это строка <{}>, это целое число <{}>, это число с плавающей точкой <{}>'
print(fmt.format('ABC', 234, 3.1415926) )


#%%
fmt = 'Это строка <{}>, это целое число <{}>, это число с плавающей точкой <{}>, а это снова строка {0}'
print(fmt.format('ABC', 234, 3.1415926) )


#%%
a = 123
b = 'I\'m a strting'
c = 3.1415926


#%%
s = f"{a} {b} {c}"
print(s)


#%%
s = f"{a:05d} {b} {c:.2f}"
print(s)

#%% [markdown]
# ### Для самостоятельного изучения:
#%% [markdown]
# 
# * регулярные выражения (regular expressions)
#%% [markdown]
# 

#%%
import re


#%%



#%%



#%%


#%% [markdown]
# # Список

#%%
# Пустой список
l = []

# Список целых чисел
l = [1, 2, 3]

# список со различными типами данных
l = ['abc', 'cde', 3.14159, 2.71828, 1]

#%% [markdown]
# ### <font color=red>Задание:</font>
# * выведите для каждого элемента списка:
#         - порядковый номер (начиная с нуля)
#         - значения
#         - тип значения

#%%
# Ваш код здесь

for i, e in enumerate(l): #пара - индекс значение
    
    print(i, e, type(e))

#%% [markdown]
# __list__ - __ключевое__ слово, которое  (формально) может использоваться, как имя переменной.<br>
# Однако, это __сильно__ не рекомендуется делать, так как это приводит к побочным эффектам

#%%
l = list( np.array([1,2,3,4]))
l


#%%
list = [1,2,3,4]


#%%
list


#%%
l = list( np.array([1,2,3,4]))
l


#%%
r = range(10)
s = str(r)
l = list(r)


#%%
r, s, l


#%%
s = str(l)
s

#%% [markdown]
# * Сравнение списков аналогично сравнению строк и выполняется поэлементно (у строк - посимвольно)

#%%
[1, 2, 3] < [1, 3, 4], 'abc' > 'cba'

#%% [markdown]
# ## Индексация списка
#%% [markdown]
# Совпадает с индексацией строк:
# * индекс размещается в квадратных скобках __\[ \]__
# * начинается с 0
# * отрицательный индекс __n__ означает __len(s) - n__ => -1 __исключает__ последний символ
# * можно указывать диапазон через двоеточие __:__
# * отсутствующий индекс перед двоеточиием означает __"с начала"__, после - __"до последнего символа включительно"__
# * можно добавить второе двоеточие, которое означает __"шаг"__
#%% [markdown]
# ### Изменение и добавление элементов

#%%
l1 = list( i*2 for i in 'abcdefghijk')
l1


#%%
l2 = list( i for i in range(10))


#%%
l1 + l2[2:4] + l2[3:7]


#%%
l = l1
l.append(l2[2:4])
l


#%%
l = l1
l.extend(l2[2:4])
l


#%%
l1

#%% [markdown]
# ### <font color=blue>Нужно запомнить</font>
#%% [markdown]
# Списки - <b>изменяемый</b> тип данных
#%% [markdown]
# ### Удаление элементов

#%%
if "abc" in globals():
    print(1)
else:
    print(2)


#%%
l.clear()
l.extend([1,2,3,4,5])
l


#%%
l.insert(5, 6)
l


#%%
l.sort(reverse=True)
l3 = l.copy()


#%%
l.remove(2)
l


#%%
l.pop()
l

#%% [markdown]
# ### <font color=red>Опишите, что делает этот код</font>

#%%
txt = 'а роза упала на лапу азора'
words = txt.split()

l = list()
for word in words:
    l.append((len(word), word))
print(l)

l.sort(reverse=True)
print(l)

res = list()
for length, word in l:
    res.append(word)

print(res)

#%% [markdown]
# ### Методы списков
#%% [markdown]
# ```python
# append() Добавляет элемент в конец списка
# extend() Добавляет все элементы списка к другому списку
# insert() Вставляет элемент на место, указнное индексом
# remove() Удаляет элемент из списка
# pop() Удаляет элемент из списка и возвращает его, как параметр
# clear() Очищает список (удаляет все элементы)
# index() Возвращает индекс первого встречающегося элемента
# count() Возвращает количество вхождений данного элемента в списке
# sort() Сортирует элементы списка в возрастающем порядке
# reverse() Изменяет порядок элементов в списке на обратный
# copy() Копирует список
# ```
#%% [markdown]
# ```python
# all() Возвращает True если все элементы списка верны или если список пустой
# any() Возвращает True если хотя бы один элементы списка верены. если списко пустой, возвращает False
# enumerate() Возвращает объект enumerate, содержащий индекс и значение всех элементов списка в виде кортежей
# len() Возвращает длину (количество элементов в) списке
# list() Преобразует любой итерируемый объект (iterable) в список (кортеж, строку, множество, словарь)
# max() Возвращает максимальный элемент в списке
# min() Возвращает минимальный элемент в списке
# sorted() Возвращает новый отсортированный список (не сортирует сам список!)
# sum() Возвращает сумму элементов в списке
# ```
#%% [markdown]
# ### <font color=red>Задание</font>
#%% [markdown]
# * Постройте частотную характеристику по словам в тексте Гамлета с использованием списков
#     * Используйте split для разбивки по пробелам
#     * удалите возвраты строк и символы, отличающиеся от букв
#     * выведите 10 наиболее часто встречающихся слов
#     * используйте zip для слияния списков в один
# * Посчитайте, сколько вообще слов в Гамлете
#%% [markdown]
# #### <font color=blue>Порядок решения:</font><br>
#     ???

#%%
import urllib

hamlet_url = "http://erdani.com/tdpl/hamlet.txt"
f = urllib.request.urlopen(hamlet_url)
hamlet_text = f.read().decode('utf-8')


#%%
# Ваш код здесь

#%% [markdown]
# ### Генераторы списков (list comprehensions)

#%%
l = [i**2 for i in range(10)]
l


#%%
l_even = [i*j for i in range(10) for  j in range(6) if i*j % 2 == 0]
l_even


#%%



#%%
list1 = ['1', '2', '3', '4', '5']
str1 = ' '.join(list1)
str1


#%%
list2 = list(range(6))
str2 = ''.join(list2)

#%% [markdown]
# ### <font color=red>Задания:</font>
#%% [markdown]
# С помощью генераторов списка:
# * Исправьте предыдущий пример, чтобы получить строку
# * просуммируйте числа от 1 до 100

#%%


#%% [markdown]
# # Кортеж
#%% [markdown]
# Кортеж (tuple) отличается от списка тем, что он __неизменяемый__ (immutable)

#%%
t = 'a', 'b', 'c', 'd', 'e'
t


#%%
t = ('a', 'b', 'c', 'd', 'e')
t


#%%
t = tuple('Some string')
t


#%%
url = 'www.mai.ru'
a,b,c = url.split('.')


#%%
a, b, c


#%%
a, b = b, a


#%%
url_parts = url.split('.')
url_parts, type(url_parts)


#%%
d = {i:c for i, c in enumerate('abcdefg')}
d


#%%
items = d.items()
items


#%%
sorted(items)

#%% [markdown]
# ### <font color=green>Полезно запомнить</font>

#%%
[1, 2, 3] < (1, 3, 4)


#%%
tuple([1, 2, 3]) > (1, 3, 4), [1, 2, 3] > list((1, 3, 4))


#%%
gen = (i for i in 'Как-то вот так генерируем')


#%%
gen, type( list( gen))

#%% [markdown]
# # Словарь

#%%
d = {1:'a', 2:'b', 3:'c', 4:'d', 5:'e'}
d


#%%
d[1]='oops'
d


#%%
d.keys(), d.values(), d.items()


#%%
sum( list( d.values()))


#%%
list(d.items())


#%%
for i in d:
    print( i, d[i])


#%%
for i, k in enumerate(d):
    print( i, k, d[k])


#%%
for i, k in enumerate( range(10)):
    print(i, k)


#%%
d.pop(2)


#%%
d[8] = 'oops!'
d


#%%
del d[3]
d

#%% [markdown]
# hashable!!!
#%% [markdown]
# ### Генераторы словарей (dictionary comprehensions)

#%%
d = {i:i**2 for i in range(11)}
d


#%%
d = (i for i in range(11))
d


#%%
list(d)


#%%
# в чем ошибка?
d = [i:i**2 for i in range(11)]
d

#%% [markdown]
# ### <font color=red>Задание</font>
#%% [markdown]
# * Перепишите код с частотной характеристикой слов в тексте Гамлета с использованием словаря

#%%


#%% [markdown]
# ## Списки и словари в аргументах функции
#%% [markdown]
# #### Скорректируйте функции так, чтобы они выдавали аргумент функции и его тип

#%%
def login(* usernamepassword):
    # Get username in the list.
    username = usernamepassword[0]
    # Get password in the list.
    password = usernamepassword[1]

    if(username=='hello') and (password == 'hello'):
        print("Login Success!")
    else:
        print("Login Failed!")

login('hello','hello')


#%%
def loginWithDictArguments(**upDict):
    # Get all keys in the dictionary.
    keys = upDict.keys();

    username='';
    password='';
    email='';

    # Loop in the dict keys.
    for key in keys:
        if(key=='username'):
            username=upDict[key]
        
        if(key=='password'):
            password=upDict[key]

        if(key=='email'):
            email=upDict[key]

    if(username=='hello') and (password=='hello'):
        print('Login Success. Your email is ' + email)
    else:
        print('Login fail. Your email is ' + email)     

loginWithDictArguments(username='hello', password='hello', email='vasya@pupkin.ru') 

#%% [markdown]
# ## Множество

#%%
a = set((0,1,2,3,4,5,6,7,8,9,3,4,5,6,7,8,0))
b = set(['a', 'b', 'c', 'd', 1, 2, 3, 4])


#%%
a,b


#%%
print('1=', a.intersection(b), '\n2=', b.intersection(a))


#%%
print('1=', a.difference(b), '\n2=', b.difference(a))


#%%
print('1=', a.symmetric_difference(b), '\n2=', b.symmetric_difference(a))


#%%
print(a.union(b))

#%% [markdown]
# ### <font color=red>Задание</font>
#%% [markdown]
# * Найдите количество уникальных слов в Гамлете с помощью множества
#%% [markdown]
# ### Стек

#%%
stack = [1, 2, 3, 4, 5]


#%%
stack.append(6)


#%%
stack.append(7)


#%%
stack


#%%
stack.pop()


#%%
stack.pop()


#%%
stack

#%% [markdown]
# # Collections

#%%
import collections

#%% [markdown]
# ### Очередь

#%%
queue = collections.deque()


#%%
from collections import deque, ChainMap, OrderedDict, Counter


#%%
queue = deque()

#%% [markdown]
# ```python
#     append(x) - добавить элемент справа
#     appendleft(x) - добавить элемент слева
#     extend(iterable) - расширить списком справа
#     extendleft(iterable) - расширить списком слева
#     pop() - извлечь элемент справа
#     popleft() - извлечь элемент слева
# ```

#%%
import random 

queue = deque()
for i in range(50):
    x = random.randint(0,1000)
    size = len(queue)
    if size == 0:
        queue.append(x)
    elif x < queue[0]:
        queue.appendleft(x)
    elif x >  queue[size-1]:
        queue.append(x)


#%%
queue

#%% [markdown]
# ### ChainMap
#%% [markdown]
# Объединяет словари без создания нового объекта "словарь". "Вохдящие" в цепочку словари используются, как ссылки

#%%
chain = ChainMap()


#%%
d1 = {'вишня': 5, 'яблоко': 1, 'персик': 8, 'груша': 2, 'тыква':7,  'баклажан':11}
d2 = {'мороженное': 27, 'яблоко': 2, 'торт': 102, 'маффин': 13, 'ром-баба':32,  'пирожок с капустой':33}


#%%
chain = ChainMap(d1, d2)


#%%
chain['вишня'], chain['торт'], chain['яблоко']


#%%
len(d1), len(d2), len(chain)

#%% [markdown]
# ### Словарь с упорядочением
# 
#%% [markdown]
# Сохраняет порядок, у котором вносились элементы списка

#%%
# обычный словарь
d = {'вишня': 5, 'яблоко': 1, 'персик': 8, 'груша': 2, 'тыква':7,  'баклажан':11}


#%%
# словарь, отсортированый по ключам
OrderedDict(sorted(d.items(), key=lambda t: t[0]))


#%%
# словарь, отсортированый позначениям
OrderedDict(sorted(d.items(), key=lambda t: t[1]))


#%%
# словарь, отсортированый по длине слова-ключа
OrderedDict(sorted(d.items(), key=lambda t: len(t[0])))

#%% [markdown]
# ### Счетчик вхождения элементов
#%% [markdown]
# Интерфейс аналогичен словарю

#%%
from collections import Counter
import urllib
import re

hamlet_url = "http://erdani.com/tdpl/hamlet.txt"
f = urllib.request.urlopen(hamlet_url)
hamlet_text = f.read().decode('utf-8')
words = re.findall(r'\w+', hamlet_text.lower())
ctr = Counter(words).most_common(10)
ctr


#%%
sum([k for i,k in ctr])

#%% [markdown]
# # Дерево
#%% [markdown]
# ### <font color=red>Задание</font>
#%% [markdown]
# * Создайте список из 1000 случайных строк, состоящих из латинских букв.
# * Каждая строка - случайной длиной от 3 до 8 символов.
# * Реализуйте бинарное дерево для строк
# * Реализуйте поиск ближайшего слова для заданного.

#%%


#%% [markdown]
# # Исключения и их обработка
#%% [markdown]
# ```python
# try:
#     You do your operations here;
#     ......................
# except ExceptionI:
#     If there is ExceptionI, then execute this block.
# except ExceptionII:
#     If there is ExceptionII, then execute this block.
#     ......................
# else:
#     If there is no exception then execute this block. 
# ```

#%%
l = list(range(10))
l[11]


#%%
try:
    print(l[9])
except IndexError:
    print('Выход за границы списка!')
else:
    print('Получилось!')


#%%
try:
    open('very_strange_file.txt')
except:
    print('Что-то не так с файлом!')
else:
    print('Странно ... Откуда он здесь?')


#%%
def func( n ):
    if n < 0:
        raise ValueError("n должен быть больше 0!", n)
    pass


#%%
func(-2)


#%%


#%% [markdown]
# ## Экзаменационные вопросы:
#%% [markdown]
# * Рекурсия
# * Регулярные выражения
# * Обработка и индексирование строк
# * Обработка и индексирование списков
# * Словари
# * Множества
# * Очередь
# * Дерево
# * Стек
# * Исключения и их обработка
#%% [markdown]
# ### К следующему занятию прочитать:
# 
#%% [markdown]
# * что такое объектно ориентированное програмирование
# * что такое функциональное программирование

