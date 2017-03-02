#include <stdio.h>

int main ()
{
	int max;
	int min;
	min = 0; 
	max = 25;
	for (int i = min; i <= max && i >= min; i = i + 4)
	{
		printf("\n");
		for (int j = min; j <= max && j >= min; j = j + 5)
		{
			printf("%d\t", i + j );
		}
	}
}
