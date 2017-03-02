#include "stdio.h"
#include "assert.h"
int main ()
{
	double x;
	double y;
	scanf ("%lg%lg", &x, &y);

	if (y != 0) {
		printf(("x + y =%lg\n"
			   "x - y =%lg\n"
			   "x * y =%lg\n"
			   "x / y =%lg\n"),
				x+y, x-y, x*y, x/y);
	}
	else {
		printf(("x + y =%lg\n"
			   "x - y =%lg\n"
			   "x * y =%lg\n"
			   "x / y = Cheta ne delit'sya =(\n"),
				x+y, x-y, x*y);
	}
}
