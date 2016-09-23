//#include <iostream>
//#include <stdio.h>
//#include <cstdlib>
//#include <vector>
//#include <map>
//#include <cctype>
//#include <cwctype>
//#include <stdexcept>
//#include <algorithm>
//#include <string>
//#include <cmath>
//#include <queue>
//#include <stack>
//
//using namespace std;
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int lenght = 0;
//	int k = 0;
//
//	cin >> lenght >> k;
//
//	if (k > lenght)
//	{
//		cout << -1 << endl;
//		return 0;
//	}
//
//	if (k == 1)
//	{
//		if (lenght == 1)
//			cout << 'a';
//		else
//			cout << -1 << endl;
//		return 0;
//	}
//
//	if (k == 2)
//	{
//		for (int i = 0; i < lenght; ++i)
//		{
//			if (i % 2)
//				cout << 'b';
//			else
//				cout << 'a';
//		}
//
//		cout << endl;
//		return 0;
//	}
//
//	for (int i = 0; i < lenght; ++i)
//	{
//		if (i == lenght - k + 2)
//		{
//			for (int j = 2; j < k; ++j)
//			{
//				char c = 'a' + j;
//				cout << c;
//			}
//
//			break;
//		}
//			 
//		if (i % 2)
//			cout << 'b';
//		else
//			cout << 'a';
//	}
//
//	cout << endl;
//
//	return 0;
//}