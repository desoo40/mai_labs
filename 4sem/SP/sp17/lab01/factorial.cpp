/*
(define(factorial n)
  (if(< n 2)
     1
     (* n (factorial (- n 1)))))
"Factorials:"
(factorial 5)
(factorial 010)
*/
#include "mlisp.h"
double factorial(double n);

double factorial(double n){
{
  return (n < 2. ? 1. : n * factorial(n - 1.));
}}
int main(){
 display("Factorials:");newline();
 display(factorial(5.));newline();
 display(factorial(010.));newline();

 std::cin.get();
 return 0;
}
