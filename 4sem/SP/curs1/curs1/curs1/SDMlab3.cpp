/*  SDM17   */
#include "mlisp.h"
double one();
double five();
double ten();
double fifteen();
double twenty();
double twenty__five();
double LARGEST__COIN();
double hundred();
double LAST__DIGIT__OF__GROUP__NUMBER();
double cc(double amount, double largest__coin);
double count__change(double amount);
double next__coin(double coin);
double GR__AMOUNT();
double help__to__disp(double temp);
//________________ 
double one()
{{
 return 1;
}}
double five()
{{
 return 5;
}}
double ten()
{{
 return 10;
}}
double fifteen()
{{
 return 15;
}}
double twenty()
{{
 return 20;
}}
double twenty__five()
{{
 return 25;
}}
double LARGEST__COIN()
{{
 return 50;
}}
double hundred()
{{
 return 100;
}}
double LAST__DIGIT__OF__GROUP__NUMBER()
{{
 return 4;
}}
double cc(double amount, double largest__coin)
{{
 return ((amount == 0) || (largest__coin == one())) ? one() : 
	true ? (!(amount > 0) || !(largest__coin > 0)) ? 0 : 
	true ? (cc(amount, next__coin(largest__coin)) + cc((amount - largest__coin), largest__coin)) : 
	false : 
	false;
}}
double count__change(double amount)
{{
 return cc(amount, LARGEST__COIN());
}}
double next__coin(double coin)
{{
 return (coin == LARGEST__COIN()) ? twenty__five() : 
	true ? (coin == twenty__five()) ? twenty() : 
	true ? (coin == twenty()) ? fifteen() : 
	true ? (coin == fifteen()) ? ten() : 
	true ? (coin == ten()) ? five() : 
	true ? 0 : 
	false : 
	false : 
	false : 
	false : 
	false;
}}
double GR__AMOUNT()
{{
 return (ten() * LAST__DIGIT__OF__GROUP__NUMBER());
}}
double help__to__disp(double temp)
{{
 display("5-10-15-20-25-50");
 newline();
 display("count-change for 100 \t= ");
 display(count__change(hundred()));
 newline();
 display("count-change for ");
 display(GR__AMOUNT());
 display(" \t= ");
 display(count__change(GR__AMOUNT()));
 return temp;
}}
int main()
{
 display("SDM variant 15"); newline();
 display(help__to__disp(one())); newline();
 return 0;
}

