#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


int main ()
{
	double a;
	double b;

	scanf ("%lf %lf", &a, &b);

	if (a > b) {
		printf("%.2lf\n", a - b);
	} 
	else {
		if (a == b && b != 0) {
			printf("%.2lf\n", a / b);
		} 
	}	
	else {
		for (int i = 0; i < 5; ++i)
		{
			++b;
			b = b+a;
		}
		printf("%.2lf %.2lf %.2lf\n", a + b, b - a, a / b);
	}
	return 0;
}