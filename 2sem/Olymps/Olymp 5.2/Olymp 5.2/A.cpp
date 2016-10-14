//#include <string>
//#include <iostream>
//#include <stdio.h>
//#include <cstdlib>
//#include <vector>
//#include <climits>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//void vec_print(vector<vector<int>> lenghts, int ver)
//{
//	for (int i = 0; i < ver; ++i)
//	{
//		for (int j = 0; j < ver; ++j)
//		{
//			cout << lenghts[i][j] << ' ';
//		}
//		cout << endl;
//	}
//}
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	
//	int ver = 0;
//	int ribs = 0;
//	queue<int> way;
//	vector<bool> vis;
//
//	cin >> ver >> ribs;
//
//	vector<vector<int>> lenghts(ver, vector<int>(ver, INT_MAX));
//
//	for (int i = 0; i < ribs; ++i)
//	{
//		int f, s, val = 0;
//
//		cin >> f >> s >> val;
//
//		lenghts[f - 1][s - 1] = val;
//	}
//
//	sort(lenghts[0].begin(), lenghts[0].end());
//
//	cout << lenghts[0][0] << endl;
//
//
//	return 0;
//}
