//#include <iostream> 
//#include <vector> 
//#include <algorithm> 
//#include <queue> 
//using namespace std;
//
//
//
//int main()
//{
//
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int size = 0;
//	int median = 0;
//	bool is_first = true;
//
//	priority_queue<int> first;
//	priority_queue<int> second;
//
//	cin >> size;
//
//	for (int i = size; i > 0; --i)
//	{
//
//		int tmp = 0;
//
//		cin >> tmp;
//
//		if (is_first == true) {
//			median = tmp;
//			is_first = false;
//		}
//
//
//		if (tmp > median)
//			second.push(-tmp);
//		else {
//			first.push(tmp);
//
//			if (first.size() == second.size())
//			{
//				first.push(median);
//				median = -second.top();
//				second.pop();
//			}
//
//			if (first.size() > second.size())
//			{
//				second.push(-median);
//				median = first.top();
//				first.pop();
//			}
//		}
//
//		cout << median << endl;
//	}
//
//	return 0;
//}