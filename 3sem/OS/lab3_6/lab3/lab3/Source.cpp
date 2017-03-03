#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Graph {
    int edges = 0;
    int vertexes = 0;

    vector<vector<bool>> adj;
    vector<bool> visited;


public:
    Graph();
    void bfs1();
    void bfs(int);
    void print();
};

Graph::Graph() {
    string s;

    ifstream graph("graph.txt");
    getline(graph, s);
    sscanf_s(s.c_str(), "%d %d", &vertexes, &edges);

    adj.resize(vertexes);
    visited.resize(vertexes, false);

    for (int i = 0; i < vertexes; ++i)
        adj[i].resize(vertexes, false);

    
    for (int i = 0; i < edges; ++i) {
        int tmp1 = 0;
        int tmp2 = 0;

        getline(graph, s);
        sscanf_s(s.c_str(), "%d %d", &tmp1, &tmp2);

        if (tmp1 > vertexes || tmp2 > vertexes) {
            cout << "ERROR: wrong input file" << endl;
            return;
        }

        adj[tmp1 - 1][tmp2 - 1] = true;
        adj[tmp2 - 1][tmp1 - 1] = true;

    }
}

void Graph::bfs1() {
    for (int v = 0; v < vertexes; ++v) {
        bfs(v);
    }
}

void Graph::bfs(int v) {
    if (visited[v])
        return;

    queue<int> q;

    q.push(v);
    visited[v] = true;

    while(!q.empty()) {
        v = q.front();
        q.pop();

        cout << v + 1 << endl;

        for (int i = 0; i < vertexes; ++i) {

            if (visited[i])
                continue;

            if (adj[v][i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }

     
}

void Graph::print() {
    for (size_t i = 0; i < vertexes; ++i) {
        for(size_t j = 0; j < vertexes; ++j) {
            if (adj[i][j])
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
}


int main(void) {
    Graph* gr = new Graph();
    gr->bfs1();
    gr->print();

}