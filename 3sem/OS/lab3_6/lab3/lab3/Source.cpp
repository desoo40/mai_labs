//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <queue>
//#include <fstream>
//#include <windows.h>
//
//#define MAX_THREADS 16
//using namespace std;
//
//int ver;
//vector<int> *adj;
//
//vector<bool> visited;
//queue<int> q;
//bool cicle = false;
//
//HANDLE hMutex;
//HANDLE hThreadArray[MAX_THREADS];
//DWORD dwThreadIdArray[MAX_THREADS];
//
//
//
//DWORD WINAPI bfs(LPVOID lpParam) {
//    WaitForSingleObject(hMutex, INFINITE);
//    int v = *(int*)lpParam;
//    --v;
//    if (visited[v]) {
//        return 0;
//    }
//    q.push(v);
//    visited[v] = true;
//
//    while (!q.empty()) {
//        v = q.front();
//        q.pop();
//        cout << v << " ";
//
//        for (size_t i = 0; i < adj[v].size(); ++i) {
//            int w = adj[v][i];
//
//            if (!visited[w]) {
//                q.push(w);
//                visited[w] = true;
//            } else 
//                cicle = true;
//        }
//    }
//    cout << endl;
//    ReleaseMutex(hMutex);
//    return 0;
//}
//
//
//void readData() {
//    string s;
//    ifstream graph("graph.txt");
//
//    getline(graph, s);
//    sscanf_s(s.c_str(), "%d", &ver);
//
//    adj = new vector<int>[ver];
//    visited.resize(ver, false);
//
//    while (getline(graph, s)) {
//        int w = 0;
//        int v = 0;
//
//        sscanf_s(s.c_str(), "%d %d", &v, &w);
//
//        adj[v].push_back(w);
//    }
//
//    visited.resize(ver, false);
//}
//
//
//int main() {
//    readData();
//    hMutex = CreateMutex(NULL, FALSE, NULL);
//
//    for (int v = 0; v < ver + 1; ++v) {
//        hThreadArray[v] = CreateThread(NULL,
//            0,
//            bfs,
//            &v,
//            NULL,
//            &dwThreadIdArray[v]);
//    }
//    WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);
//    for (int i = 0; i < MAX_THREADS; i++) CloseHandle(hThreadArray[i]);
//
//    for (int i = 0; i < ver; ++i) {
//        adj[i].clear();
//    }
//    delete[] adj;
//
//    visited.clear();
//    if (cicle)
//        cout << "Graph with cicles" << endl;
//    else
//        cout << "Graph without cicles" << endl;
//
//    return 0;
//}