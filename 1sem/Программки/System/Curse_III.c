// x /(9 + x^2)

//((-1)^n *(x^(2n+1))) / 9 ^(n+1)

#include "stdio.h"
#include "math.h"

int main(void)
{
	long double summ_teylors;
	long double func;
	unsigned int iterations = 0U;
	printf("------------------------------------------------------------\n");
	printf("|   X   |  Summ of Taylor's row  |  Function  | Iterations |\n");
	printf("------------------------------------------------------------\n");

	for (long double x = -1.0f; x <= 1.0f; x += 0.02f) {
		
		summ_teylors = (pow(-1, iterations) * pow(x, 2 * iterations + 1)) / pow(9, iterations + 1);
		func = x / (9 + pow(x, 2));
		printf("| %5.2Lf |         %-13.2Lf  | %7.2Lf    | %-9d  |\n", x, summ_teylors, func, iterations);
		printf("|----------------------------------------------------------|\n");
		++iterations;	
	}
	return 0;
}