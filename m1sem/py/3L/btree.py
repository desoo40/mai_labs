from difflib import ndiff

def dist(value1, value2):
        return sum([1 for i in ndiff(value1, value2) if '+' in i or '-' in i])

class StrBinTree:
    '''
    Класс бинарного дерева с функциями поиска и выдачи расстояния до ближайшей сохраненной строки:
     '''
    def __init__(self):
        self.str = None
        self.left = None
        self.right = None

    def add(self, s):
        '''
        добавляет строку в дерево
        '''
        if self.str == None:
            self.str = s
            self.left = StrBinTree()
            self.right = StrBinTree()

        elif s == self.str:
            print(f"{s} is already in tree")
            return
        elif s > self.str:
            self.right.add(s)
        else:
            self.left.add(s)

    # Каков смысл этой функции?
    def __add__(self, s):
        '''
        ваше описание
        '''
        self.add(s)

    def isin(self, s):
        '''
        возвращает True, если есть точно такая же строка, или False, если её нет
        '''
        if self.str == None:
            return False
        elif self.str == s:
            return True
        elif s > self.str:
            return self.right.isin(s)
        else:
            return self.left.isin(s)

    def find_min(self):
        if not self.left.str:
            return self.str
        
        return self.left.find_min()
         

    def remove(self, s):
        '''
        удаляет строку. Удаление производится только в случае точного совпадения
        строки с указанной. Возвращает 0, если удаление выполнено, и 1 в остальных случаях
        '''
        if self.str == None:
            return 1

        elif s > self.str:
            return self.right.remove(s)

        elif s < self.str:
            return self.left.remove(s)

        else:
            if self.left.str and self.right.str:
                tmp = self.right.find_min()
                self.str = tmp
                self.right.remove(tmp)
            elif self.left.str:
                self.str = self.left.str
                self.right = self.left.right
                self.left = self.left.left

            elif self.right.str:
                self.str = self.right.str
                self.left = self.right.left
                self.right = self.right.right
            
            else:
                self.str = None
            
            return 0

    def get(self, s):
        '''
        возвращает ближайшую с лексической точки зрения строку и расстояние строки-аргумента
        до нее
        '''
        if self.str == None:
            return None

        elif self.str == s:
            return s, 0

        elif s > self.str:
            if self.right.str != None:
                return self.right.get(s)
            else:
                return self.str, dist(self.str, s)
        else:
            if self.left.str != None:
                return self.left.get(s)
            else:
                return self.str, dist(self.str, s)

    def __len__(self):
        '''
        возвращает количество строк в дереве
        '''
        if self.str == None:
            return 0

        l = 1       
        l += len(self.left)
        l += len(self.right)

        return l

    def to_list(self):
        '''
        возвращает все строки в виде упорядоченного списка
        '''
        if self.str == None:
            return []

        l = []

        l += self.left.to_list()
        l.append(self.str)
        l += self.right.to_list()

        return l
    
    def print_tree(self, n):
        if self.str == None:
            return
        
        print('\t' * n, self.str)

        self.right.print_tree(n + 1)
        self.left.print_tree(n + 1)

import random, string

tree = StrBinTree()


# list_str = list(string.ascii_lowercase)
# random.shuffle(list_str)

# print(list_str)

# for i in list_str:
#     tree.add(i)

tree.add("8")
tree.add("5")
tree.add("2")
tree.add("9")
tree.print_tree(0)
tree.remove("5")
tree.print_tree(0)


print(tree.to_list())
print(tree.isin("2"))
print(tree.isin("3"))

print(tree.get("1330"))
print(tree.get("2"))