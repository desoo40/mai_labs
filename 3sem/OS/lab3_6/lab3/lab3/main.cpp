#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <fstream>

using namespace std;

int n; //���������� ������ � �������
int m; //���������� ��� � �������
vector<int> *adj; //������ ��������� �������
				  //������ ��� �������� ���������� � ���������� � �� ���������� ��������
vector<bool> used;
queue<int> q; //������� ��� ���������� ������ ��� ������ � ������

			  //��������� ������ � ������
void bfs(int v) {
	if (used[v]) { //���� ������� �������� ����������, �� �� ���������� �� ��� ����� ���������
		return;
	}
	q.push(v); //�������� ����� �� ������� v
	used[v] = true; //�������� ������� ��� ����������
	while (!q.empty()) {
		v = q.front(); //��������� ������� �� �������
		q.pop();
		printf("%d ", (v + 1));
		//��������� ����� �� ���� ������, ������� � �������� v
		for (size_t i = 0; i < adj[v].size(); ++i) {
			int w = adj[v][i];
			//���� ������� ��� ���� ��������, �� ���������� ��
			if (used[w]) {
				continue;
			}
			q.push(w); //��������� ������� � ������� ������
			used[w] = true; //�������� ������� ��� ����������
		}
	}
}

//��������� ���������� ������ � �������
void readData() {
	string s; // ���� ����� ������ ��������� ������
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

	//�������� ��� �������, ��� ������������
	used.resize(n, false);
}

void run() {
	readData();
	for (int v = 0; v < n; ++v) {
		bfs(v);
	}
	//����������� ������
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