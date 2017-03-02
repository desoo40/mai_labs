#include <stdio.h>
float calculate

int main ()
{

	int farh;
	printf("Celsius     Farh\n");
	for (farh = 300; farh >= 0; farh = farh - 20)
	{
		printf("%7d  =  %4.1f\n", farh, (5.0/9.0)*(farh-32) );

	}
} 
