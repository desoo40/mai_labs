class StrBinTree:
    '''
    Класс бинарного дерева с функциями поиска и выдачи расстояния до ближайшей сохраненной строки:
     '''
    def __init__(self):
        self.node_string = None
        self.left_node = None
        self.right_node = None
    
    def add(self, s):
        '''
        добавляет строку в дерево
        '''
        if self.node_string == None:
            self.node_string = s
            self.left_node = StrBinTree()
            self.right_node = StrBinTree()

        elif s == self.node_string:
            print(f"{s} is already in tree")
            return
        elif s > self.node_string:
            self.right_node.add(s)
        else:
            self.left_node.add(s)
    
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
        if self.node_string == None:
            return False
        elif self.node_string == s:
            return True
        elif s > self.node_string:
            self.right_node.isin(s)
        else:
            self.left_node.isin(s)
        
    def remove(self, s):
        '''
        удаляет строку. Удаление производится только в случае точного совпадения
        строки с указанной. Возвращает 0, если удаление выполнено, и 1 в остальных случаях
        '''
        if self.node_string == None:
            return 1
        elif self.node_string == s:
            self.node_string = None
            return 0
        elif s > self.node_string:
            self.right_node.remove(s)
        else:
            self.left_node.remove(s)
        
    def get(self, str):
        '''
        возвращает ближайшую с лексической точки зрения строку и расстояние строки-аргумента
        до нее
        '''
        pass

    def __len__(self):
        '''
        возвращает количество строк в дереве
        '''
        if self.node_string == None:
            return 0

        l = 1       
        l += len(self.left_node)
        l += len(self.right_node)
    
        return l
    
    def to_list(self):
        '''
        возвращает все строки в виде упорядоченного списка
        '''
        if self.node_string == None:
            return []
        
        l = []
       
        l += self.left_node.to_list()
        l.append(self.node_string)
        l += self.right_node.to_list()
    
        return l

tree = StrBinTree()

tree.add("sdfkksd")
tree.add("e;llwfdsf")
tree.add("e;sdfsdfllwfdsf")

print(tree.to_list())
print(len(tree))