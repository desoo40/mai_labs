#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int edges;
    int vertexes;

    vector<vector<bool>> adj;

public:
    Graph(std::istream &is);
    void bfs();
    void print();
};

Graph::Graph(std::istream &is) {
    is >> vertexes >> edges;
    
    for (int i = 0; i < edges; ++i) {
        int tmp1 = 0;
        int tmp2 = 0;

        is >> tmp1 >> tmp2;

        adj[tmp1 - 1][tmp2 - 1] = true;
    }
}

void Graph::bfs() {
}

void Graph::print() {
    for (size_t i = 0; i < vertexes; ++i) {
        for(size_t j = 0; j < vertexes; ++j) {
            if (adj[i][j])
                cout << 1;
        }
    }
}


int main(void) {
    Graph* gr = new Graph(cin);

    gr->print();

}