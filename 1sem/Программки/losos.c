#include <stdio.h>
float calculate (float m);

int main ()
{

	int farh;
	printf("Celsius     Farh\n");
	for (farh = 300; farh >= 0; farh = farh - 20)
	{
		printf("%7d  =  %4.1f\n", farh, calculate(farh));

	}
} 

float calculate (float farhen)
{
	farhen = (5.0/9.0)*(farhen-32);
	return farhen;
}
