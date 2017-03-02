#include "stdio.h"

int main ()
{
	int iter = 1;
	int num;
	while ((scanf ("%d", &num)) != EOF) {
		if (num % iter == 0) {
			printf("%d ", num);
			
		}
		++iter;
	}
	printf("\n");
	return 0;
}