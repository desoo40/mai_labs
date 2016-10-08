//#include <string>
//#include <iostream>
//#include <stdio.h>
//#include <cstdlib>
//#include <vector>
//#include <map>
//#include <cmath>
//
//using namespace std;
//
//int max(int a, int b)
//{
//	return a > b ? a : b;
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int bugs = 0;
//	int lenght = 0;
//	int l_extreme = 0;
//	int r_extreme = 0;
//	cin >> bugs >> lenght;
//
//	for (int i = 0; i < bugs; ++i) {
//		int tmp = 0;
//		char c;
//
//		cin >> tmp >> c;
//
//		if (c == 'L' && tmp > r_extreme)
//			r_extreme = tmp;
//
//		if (c == 'R' && lenght - tmp > l_extreme)
//			l_extreme = lenght - tmp;
//	}
//
//	cout << max(l_extreme, r_extreme) << endl;
//	return 0;
//}