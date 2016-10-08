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
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int dots = 0;
//	int extrem_distant = 0;
//	int vars = 0;
//
//	cin >> dots >> extrem_distant;
//
//	vector<int> coordinates(dots);
//
//	for (int i = 0; i < coordinates.size(); ++i)
//		cin >> coordinates[i];
//
//	for (int i = 0; i < coordinates.size() - 2; ++i)
//	{
//		for (int j = i + 2; j < coordinates.size(); ++j)
//		{
//			
//			if (coordinates[j] - coordinates[i] > extrem_distant) {
//				vars += (j - i + 1 ) * (j - i) / 2;
//				break;
//			}
//		
//		}
//	}
//
//	cout << vars << endl;
//
//	return 0;
//}