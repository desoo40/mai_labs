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
//
//bool increment_string(char *c, size_t size)
//{
//	if (size == -1)
//		return false;
//	if (*c == 'z') {
//		*c = 'a';
//		return increment_string(--c, size - 1);
//	}
//
//	++*c;
//	return true;
//}
//
//
//bool compare_strings(string f, string s)
//{
//	for (int i = 0; i < s.size(); ++i)
//	{
//		if (f[i] > s[i])
//			return false;
//
//		if (f[i] == s[i])
//			continue;
//		
//		if (f[i] < s[i])
//			return true;
//	}
//
//	return false;
//}
//
//int main(void)
//{
//		string first;
//		string second;
//		long long shash = 0;
//		int base = 31;
//
//		cin >> first >> second;
//
//
//		if (increment_string(&first[first.size() - 1], first.size() - 1))
//		{
//			if (compare_strings(first, second)) {
//				cout << first << endl;
//				return 0;
//			}
//		}
//
//		cout << "No such string" << endl;
//		return 0;
//}
