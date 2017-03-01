//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main (void)
//{
//    int size = 0;
//
//    cin >> size;
//
//    vector<bool> resheto(size, 1);
//
//    for (int i = 2; i * i <= size; ++i) {
//        if (resheto[i]) {
//            for (int j = i * i; j < size; j += i) {
//                resheto[j] = 0;
//            }
//        }
//    }
//
//    for (size_t i = 2; i < resheto.size(); ++i) {
//        if (resheto[i]) {
//            cout << i << " ";
//        }
//    }
//
//    cin >> size;
//
//    for (int i = 2; i * i <= size; ++i) {
//        if (!(size % i))
//            cout << "YES" << endl;
//    }
//
//}