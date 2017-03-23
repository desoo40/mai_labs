#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>

#define MAX_THREADS 16

using namespace std;

HANDLE hMutex;

class Graph {
    int vertexes = 0;

    vector<int> *adj;
    vector<bool> visited;


public:
    bool cicle = false;
    Graph();
    void bfs1();
    void bfs(int);
    void print();
};

Graph::Graph() {
    string s;
    ifstream graph("graph.txt");

    getline(graph, s);
    sscanf_s(s.c_str(), "%d", &vertexes);

    adj = new vector<int>[vertexes];
    visited.resize(vertexes, false);

    while(getline(graph, s)) {
        int w = 0;
        int v = 0;

        sscanf_s(s.c_str(), "%d %d", &v, &w);
        
        adj[v].push_back(w);
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

    HANDLE  hThreadArray[MAX_THREADS];
    DWORD   dwThreadIdArray[MAX_THREADS];
    hMutex = CreateMutex(NULL, FALSE, NULL);

    while(!q.empty()) {
        v = q.front();
        cout << v << " ";
        q.pop();

        for (size_t i = 0; i < adj[v].size(); ++i) {
            int w = adj[v][i];
            
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
            } else {
                cout << "KEK" << endl;
            }
        }
    }

     
}

int main(void) {
    Graph* gr = new Graph();
    gr->bfs1();
}