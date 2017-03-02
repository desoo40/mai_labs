#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define i 1000

int main ()
{
	int A;
	printf("GIVE ME A = ");
	scanf ("%d", &A);
	float SUM; 
	SUM = 0.0f;
	for (int k = 1; i <= i; k++)
	{
		SUM = SUM + abs (k-4);
		if (SUM > A) {
			printf("First member bigger then A is %.0f. Number (k) = %d\n", SUM , k );
			break;
		}
		else {
			printf("%d member is smaller then A (%.0f < A)\n", k, SUM );
		}
	}
return 0;
}
