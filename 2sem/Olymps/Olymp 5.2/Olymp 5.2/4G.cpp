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
//#define mod 1000000007
//
//using namespace std;
//
//int main(void)
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	long long n = 0;
//	long long fibon = 0;
//	long long tmp1 = 0;
//
//	cin >> n;
//
//	for (long long i = 0; i <= n; ++i)
//	{
//		if (i == 0) {
//			fibon = 0;
//			continue;
//		}
//
//		if (i == 1) {
//			fibon = 1;
//			continue;
//		}
//
//		if (fibon > mod)
//			fibon %= mod;
//
//		long long tmp2 = fibon;
//		fibon = fibon + tmp1;
//
//		tmp1 = tmp2;
//	}
//
//	cout << fibon << endl;
//
//	return 0;
//}