/*  SDM17   */
#include "mlisp.h"
double two();
double one();
double smallest__divisor(double n);
double SDMsquare(double n);
double find__divisor(double n, double test__divisor);
bool divides_Q(double a, double b);
bool prime_Q(double n);
//________________ 
double two(){{
 ;
}}
double one(){{
 ;
}}
double smallest__divisor(double n){{
 	return (find__divisor(n, two)));
}}
double SDMsquare(double n){{
 	return ((n * n));
}}
double find__divisor(double n, double test__divisor){{
 	return (((SDMsquare(test__divisor) > n)) ? (n) : 
(true) ? ((divides_Q(test__divisor, n)) ? (test__divisor) : 
(true) ? (find__divisor(n, (test__divisor + one)))) : 
0) : 
0);
}}
bool divides_Q(double a, double b){{
  return (remainder(b, a) == 0);
}}
bool prime_Q(double n){{
  return (n == smallest__divisor(n));
}}
int main(){
 display(prime_Q(one))); newline();
 display(prime_Q(two))); newline();
 std::cin.get();
 return 0;
}

