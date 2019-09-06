import networkx as nx
import matplotlib.pyplot as plt
import numpy

import vk_auth
import vkontakte
import time
 
def get_groups_users(groups_list):
    groups_out = {}
    (token,user_id) = vk_auth.auth('your_login', 'your_password', '2951857', 'groups')
    vk = vkontakte.API(token=token)
    for group in groups_list:
        groups_out[group] = vk.get('groups.getMembers', group_id=group, sort='id_asc', offset=100, count=10)
        time.sleep(1)
    return groups_out

def make_graph(groups_out):
    graph = nx.Graph()
    groups_out = groups_out.items()
    for i_group in xrange(len(groups_out)):
        graph.add_node(groups_out[i_group][0], size=groups_out[i_group][1]['count'])
        for k_group in xrange(i_group+2, len(groups_out)):
            intersection = set(groups_out[i_group][1]['users']).intersection(set(groups_out[k_group][1]['users']))
            if len(intersection) > 0:
                graph.add_edge(groups_out[i_group][0], groups_out[k_group][0], weight=len(intersection))
    return graph

def plot_graph(graph, adjust_nodesize):
    pos=nx.spring_layout(graph, k=1)
    nodesize = [graph.node[i]['size']/adjust_nodesize for i in graph.nodes()]
    edge_mean = numpy.mean([graph.edge[i[0]][i[1]]['weight'] for i in graph.edges()])
    edge_std_dev = numpy.std([graph.edge[i[0]][i[1]]['weight'] for i in graph.edges()])
    edgewidth = [((graph.edge[i[0]][i[1]]['weight'] - edge_mean)/edge_std_dev) for i in graph.edges()]
    nx.draw_networkx_nodes(graph, pos,node_size=nodesize, node_color='y', alpha=0.6)
    nx.draw_networkx_edges(graph,pos,width=edgewidth,edge_color='b')
    nx.draw_networkx_labels(graph,pos,fontsize=10)
    plt.savefig('/path/to/save/figure')
    plt.show()

if __name__ == '__main__':
    groups = ['oldlentach', 'echomsk', 'meduzaproject', 'tvrain', 'bbc',
    '1tv', 'izvestia', 'rt_russian', 'lentaru', 'ntv',
    'habr', 'postnauka', 'cloudytech', 'space_live', 'popularmechanics',
    'inbest', 'lovestime', 'orealno', 'devpoymut', 'padik_adik']
    groups_out = get_groups_users(groups)
    graph = make_graph(groups_out)
    plot_graph(graph, 500)