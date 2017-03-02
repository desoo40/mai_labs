#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


int main ()
{
	int year_b;
	int month_b;
	int day_b;
	int curr_d;
	int curr_m;
	int curr_y;
	
	scanf ("%d%d%d", &day_b, &month_b, &year_b);
	scanf ("%d%d%d", &curr_d, &curr_m, &curr_y);
	
	if (curr_d >= day_b && curr_m >= month_b)
		{
			printf("%d\n", curr_y - year_b);
		}
	if (curr_y <= 0 || 31 >= curr_d <= 0 || 12 >= curr_m <= 0 || 31 >= day_b <= 0 || 12 >= month_b <= 0 || year_b <= 0 || )
	{
		printf("Are you fucking kidding me???\n");
	}
	else 
	{
		printf("%d\n", curr_y - year_b - 1);
	}
	return 0;
}
