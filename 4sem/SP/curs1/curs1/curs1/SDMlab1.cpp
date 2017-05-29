/*  SDM17   */
#include "mlisp.h"
double two();
double one();
double six();
double twelwe();
double thirteen();
double twenty__nine();
double thirty();
double smallest__divisor(double n);
double SDMsquare(double n);
double find__divisor(double n, double test__divisor);
bool divides_Q(double a, double b);
bool prime_Q(double n);
//________________ 
double two()
{{
 return 2;
}}
double one()
{{
 return 1;
}}
double six()
{{
 return 6;
}}
double twelwe()
{{
 return 12;
}}
double thirteen()
{{
 return 13;
}}
double twenty__nine()
{{
 return 23;
}}
double thirty()
{{
 return 30;
}}
double smallest__divisor(double n)
{{
 return find__divisor(n, two());
}}
double SDMsquare(double n)
{{
 return (n * n);
}}
double find__divisor(double n, double test__divisor)
{{
 return (SDMsquare(test__divisor) > n) ? n : 
	true ? divides_Q(test__divisor, n) ? test__divisor : 
	true ? find__divisor(n, (test__divisor + one())) : 
	false : 
	false;
}}
bool divides_Q(double a, double b)
{{
 return (remainder(b, a) == 0);
}}
bool prime_Q(double n)
{{
 return (n == smallest__divisor(n));
}}
int main()
{
 display(prime_Q(one())); newline();
 display(prime_Q(two())); newline();
 display(prime_Q(six())); newline();
 display(prime_Q(twelwe())); newline();
 display(prime_Q(thirteen())); newline();
 display(prime_Q(twenty__nine())); newline();
 display(prime_Q(thirty())); newline();
 return 0;
}

