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
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	short n = 0;
//
//	cin >> n;
//
//	if (n == 1) {
//		cout << "YES" << endl;
//		return 0;
//	}
//
//	vector<int> digits(1001, 0);
//
//	for(int i = 0; i < n; ++i)
//	{
//		int tmp = 0;
//
//		cin >> tmp;
//
//		++digits[tmp];
//	}
//
//	sort(digits.begin(), digits.end());
//
//	if (n % 2) {
//		if (digits[digits.size() - 1] > n / 2 + 1)
//			cout << "NO" << endl;
//		else
//			cout << "YES" << endl;
//	}
//	else {
//		if (digits[digits.size() - 1] > n / 2)
//			cout << "NO" << endl;
//		else
//			cout << "YES" << endl;
//	}
//
//	return 0;
//}