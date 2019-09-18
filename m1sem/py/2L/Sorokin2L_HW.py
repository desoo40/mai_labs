# * Создайте список из 1000 случайных строк, состоящих из латинских букв.
# * Каждая строка - случайной длиной от 3 до 8 символов.
# * Реализуйте бинарное дерево для строк
# * Реализуйте поиск ближайшего слова для заданного.

import random
import string

def gen_strings(qty):
    l = []

    for i in range(qty):
        x = random.randint(3,8)
        l.append(''.join(random.choices(string.ascii_lowercase, k=x)))

    return l

def add_to_tree(s, node):
    if (s == node):
        print(f"\'{s}\' is already in tree")
        return

    if (s > node):
        if (bin_tree[node][1] == None):
            bin_tree[node][1] = s
            bin_tree[s] = [None, None]
        else:
            add_to_tree(s, bin_tree[node][1])
    
    else:
        if (bin_tree[node][0] == None):
            bin_tree[node][0] = s
            bin_tree[s] = [None, None]
        else:
            add_to_tree(s, bin_tree[node][0])

def find_nearest(f_str, node):
    if (f_str == node):
        print(f"Find same word! \'{f_str}\' == \'{node}\''")
        return

    if (f_str > node):
        if (bin_tree[node][1] == None):
            print(f"Nearest for \'{f_str}\' is \'{node}\''")
            return
        else:
            find_nearest(f_str, bin_tree[node][1])
    
    else:
        if (bin_tree[node][0] == None):
            print(f"Nearest for {f_str} is {node}")
            return
        else:
            find_nearest(f_str, bin_tree[node][0])

def print_tree(node, n):
    if (node == None):
        return

    print('\t' * n, node)

    print_tree(bin_tree[node][1], n + 1)
    print_tree(bin_tree[node][0], n + 1)


list_str = gen_strings(10)

print(list_str)

root = list_str.pop(0)

bin_tree = {}
bin_tree[root] = [None, None]

for i in list_str:
    add_to_tree(i, root)

print_tree(root, 0)

add_to_tree('egkok', root)
find_nearest('egkok', root)
print_tree(root, 0)
