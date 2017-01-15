#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <fstream>

using namespace std;

int n; //количество вершин в орграфе
int m; //количество дуг в орграфе
vector<int> *adj; //список смежности орграфа
				  //массив для хранения информации о пройденных и не пройденных вершинах
vector<bool> used;
queue<int> q; //очередь для добавления вершин при обходе в ширину

			  //процедура обхода в ширину
void bfs(int v) {
	if (used[v]) { //если вершина является пройденной, то не производим из нее вызов процедуры
		return;
	}
	q.push(v); //начинаем обход из вершины v
	used[v] = true; //помечаем вершину как пройденную
	while (!q.empty()) {
		v = q.front(); //извлекаем вершину из очереди
		q.pop();
		printf("%d ", (v + 1));
		//запускаем обход из всех вершин, смежных с вершиной v
		for (size_t i = 0; i < adj[v].size(); ++i) {
			int w = adj[v][i];
			//если вершина уже была посещена, то пропускаем ее
			if (used[w]) {
				continue;
			}
			q.push(w); //добавляем вершину в очередь обхода
			used[w] = true; //помечаем вершину как пройденную
		}
	}
}

//процедура считывания данных с консоли
void readData() {
	string s; // сюда будем ложить считанные строки
	ifstream graph("graph.txt");

	getline(graph, s);

	sscanf_s(s.c_str(), "%d %d", &n, &m);

	adj = new vector<int>[n];

	while(getline(graph, s))
	{
		int v, w;
		sscanf_s(s.c_str(), "%d %d", &v, &w);
		v--;
		w--;
		adj[v].push_back(w);
	}

	//помечаем все вершины, как непосещенные
	used.resize(n, false);
}

void run() {
	readData();
	for (int v = 0; v < n; ++v) {
		bfs(v);
	}
	//освобождаем память
	for (int i = 0; i < n; ++i) {
		adj[i].clear();
	}
	delete[] adj;

	used.clear();
}

int main()
{
	run();
	return 0;
}