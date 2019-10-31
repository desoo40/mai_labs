import networkx as nx
import sys

l = list()
G = nx.DiGraph()

for line in sys.stdin:
    l.append(line.replace('\n', '').split(' '))

for i in range(1, len(l)):
    G.add_edge(l[i][0], l[i][1])

if len(list(nx.simple_cycles(G))) == 0:
    print('TRUE')
else:
    print("FALSE")