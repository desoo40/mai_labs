#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <fstream>
#include <windows.h>

#define MAX_THREADS 16
using namespace std;

int ver;
vector<int> *adj;

vector<bool> visited;
queue<int> q;
bool cicle = false;

HANDLE hMutex;
HANDLE hThreadArray[MAX_THREADS];
DWORD dwThreadIdArray[MAX_THREADS];



DWORD WINAPI obxod(LPVOID lpParam)
{
    WaitForSingleObject(hMutex, INFINITE);
	int v = *(int*)lpParam;

	for (size_t i = 0; i < adj[v].size(); ++i) {
		int w = adj[v][i];

        if (!visited[w]) {
            q.push(w);
            visited[w] = true;
        } else 
            cicle = true;
	}
    ReleaseMutex(hMutex);
	return 0;
}

void bfs(int v) {
	if (visited[v]) {
		return;
	}
	q.push(v);
	visited[v] = true;
    hMutex = CreateMutex(NULL, FALSE, NULL);
	while (!q.empty()) {
		v = q.front();
		q.pop();
        cout << v << " ";

		hThreadArray[v] = CreateThread(NULL,
			0,
			obxod,
			&v,
			NULL,
			&dwThreadIdArray[v]);
	}
    cout << endl;
    WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);
    for (int i = 0; i < MAX_THREADS; i++) CloseHandle(hThreadArray[i]);


}



void readData() {
    string s;
    ifstream graph("graph.txt");

    getline(graph, s);
    sscanf_s(s.c_str(), "%d", &ver);

    if (ver == 0) {
        cerr << "No data" << endl;
        return;
}

    adj = new vector<int>[ver];
    visited.resize(ver, false);

    while (getline(graph, s)) {
        int w = 0;
        int v = 0;

        sscanf_s(s.c_str(), "%d %d", &v, &w);

        adj[v].push_back(w);
    }

	visited.resize(ver, false);
}


int main()
{
    readData();

    for (int v = 0; v < ver; ++v) {
        bfs(v);
    }


    for (int i = 0; i < ver; ++i) {
        adj[i].clear();
    }
    delete[] adj;

    visited.clear();
    if (cicle)
        cout << "Graph with cicles" << endl;
    else
        cout << "Graph without cicles" << endl;
    
	return 0;
}