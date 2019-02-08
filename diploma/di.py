import csv
import matplotlib.pyplot as plt
import networkx as nx

with open('data.csv', mode='r') as csv_file:
    csv_reader = csv.DictReader(csv_file)
    line_count = 0

    G = nx.Graph()

    for row in csv_reader:
        if line_count == 0:
            print(f'Column names are {", ".join(row)}')
            line_count += 1

        G.add_node(row["nameOrig"])
        G.add_node(row["nameDest"])

        G.add_edge(row["nameOrig"], row["nameDest"])

        line_count += 1

        if line_count > 50:
            break

    nx.draw(G, node_size=20, with_labels=False)
    plt.show()