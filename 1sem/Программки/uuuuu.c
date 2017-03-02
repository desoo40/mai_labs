#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


int main ()
{
	int year_b;
	int month_b;
	int day_b;
	int age;
	/* b -born */
	printf("When were you born?\n"
			"Year: \n");
	scanf ("%d", year_b);
	
	printf("Month: \n");
	scanf ("%d", month_b);
	
	printf("Day: \n");
	scanf ("%d", day_b);

	//7.11.15//

	if (month_b > 11) {
	}
	return 0;
}

/*double accum_10 (double w, char b) {
	w *= 10;
	w += (b - '0');
	return w;
}

double accum_01 (double w, char b, int q) {
	w *= 10;
	w += (b - '0');
	++q;
	return w;
	return q;
}*/