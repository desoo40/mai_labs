//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <queue>
//#include <fstream>
//#include <windows.h>
//#define MAX_THREADS 16
//using namespace std;
//
//int n;
//int m;
//vector<int> *adj;
//
//vector<bool> used;
//queue<int> q;
//
//HANDLE hThreadArray[MAX_THREADS];
//DWORD dwThreadIdArray[MAX_THREADS];
//
//
//
//DWORD WINAPI obxod(LPVOID lpParam)
//{
//	int v = *(int*)lpParam;
//
//	for (size_t i = 0; i < adj[v].size(); ++i) {
//		int w = adj[v][i];
//		cout << "YES" << endl;
//
//
//		if (used[w]) {
//			continue;
//		}
//		q.push(w);
//		used[w] = true;
//	}
//
//	return 0;
//}
//
//void bfs(int v) {
//	if (used[v]) {
//		return;
//	}
//	q.push(v);
//	used[v] = true;
//	while (!q.empty()) {
//		v = q.front();
//		q.pop();
//		printf("%d ", (v + 1));
//
//		hThreadArray[v] = CreateThread(NULL,
//			0,
//			obxod,
//			&v,
//			CREATE_SUSPENDED,
//			&dwThreadIdArray[v]);
//		ResumeThread(hThreadArray[v]);
//	}
//
//	WaitForMultipleObjects(MAX_THREADS, hThreadArray, TRUE, INFINITE);
//
//	for (int i = 0; i < MAX_THREADS; i++)
//	{
//		if (hThreadArray[i] == (HANDLE)0xcccccccc) continue;
//		CloseHandle(hThreadArray[i]);
//	}
//
//
//}
//
//
//
//void readData() {
//	string s;
//	ifstream graph("graph.txt");
//
//	getline(graph, s);
//
//	sscanf_s(s.c_str(), "%d %d", &n, &m);
//
//	adj = new vector<int>[n];
//
//	while (getline(graph, s))
//	{
//		int v, w;
//		sscanf_s(s.c_str(), "%d %d", &v, &w);
//		v--;
//		w--;
//		adj[v].push_back(w);
//	}
//
//	used.resize(n, false);
//}
//
//
//int main()
//{
//    readData();
//
//    for (int v = 0; v < n; ++v) {
//        bfs(v);
//    }
//
//
//    for (int i = 0; i < n; ++i) {
//        adj[i].clear();
//    }
//    delete[] adj;
//
//    used.clear();
//	return 0;
//}