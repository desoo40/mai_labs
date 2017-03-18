//scopex.cpp
/*
(define(f x)
  (define x 5)
  x)
(f 1)
*/
#include <iostream>
using namespace std;
double f(double x){
  double x=5;
  return x;
}
int main(){
 cout << f(1) << endl;
 cin.get();
 return 0;
}
