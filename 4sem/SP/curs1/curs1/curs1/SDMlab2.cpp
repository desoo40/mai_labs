/*  SDM17   */
#include "mlisp.h"
double one();
double two();
double six();
double twelwe();
double thirteen();
double twenty__nine();
double thirty();
double tolerance();
double half__interval__metod(double a, double b, double a__value, double b__value);
double __SDM17__try(double neg__point, double pos__point, double midpoint, double test__value);
bool close__enough_Q(double x, double y);
double average(double x, double y);
double root(double a, double b, double temp);
double fun(double z);
//________________ 
double one()
{{
 return 1;
}}
double two()
{{
 return 2;
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
double tolerance()
{{
 return 1.0e-5;
}}
double half__interval__metod(double a, double b, double a__value, double b__value)
{{
 a__value = fun(a);
 b__value = fun(b);
 return (!(0 > a__value) || !(b__value > 0)) ? __SDM17__try(a, b, 0, 0) : 
	true ? (!(a__value > 0) || !(0 > b__value)) ? __SDM17__try(b, a, 0, 0) : 
	true ? (b + one()) : 
	false : 
	false;
}}
double __SDM17__try(double neg__point, double pos__point, double midpoint, double test__value)
{{
 midpoint = average(neg__point, pos__point);
 test__value = fun(midpoint);
 display("+");
 return close__enough_Q(neg__point, pos__point) ? midpoint : 
	true ? (test__value > 0) ? __SDM17__try(neg__point, midpoint, 0, 0) : 
	true ? (0 > test__value) ? __SDM17__try(midpoint, pos__point, 0, 0) : 
	true ? midpoint : 
	false : 
	false : 
	false;
}}
bool close__enough_Q(double x, double y)
{{
 return (tolerance() > abs((x - y)));
}}
double average(double x, double y)
{{
 return (((double)1 / two()) * (x + y));
}}
double root(double a, double b, double temp)
{{
 temp = half__interval__metod(a, b, 0, 0);
 newline();
 display("interval=\t[");
 display(a);
 display(" , ");
 display(b);
 display("]\n");
 display("discrepancy=\t");
 display(fun(temp));
 newline();
 display("root=\t\t");
 display((((temp - b) - one()) == 0) ? "[bad]"
		:"[good]");
 return temp;
}}
double fun(double z)
{{
 z = ((z - (((double)1 / thirty()) * twenty__nine())) - ((double)1 / pi));
 return (((z - atan((two() * z))) - log((pi * z))) - six());
}}
int main()
{
 display("SDM variant 29"); newline();
 display(root(twelwe(), thirteen(), 0)); newline();
 return 0;
}

