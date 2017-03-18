//scopef.cpp
/*
(define(f f)
  (* f f) )
(f 7)
*/
#include <iostream>
using namespace std;
double f(double f){
  return f*f;
}
int main(){
 cout << f(7) << endl;
 cin.get();
 return 0;
}
