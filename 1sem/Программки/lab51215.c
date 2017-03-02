#include "stdio.h"
#define n 5
#define m 6

int main(void)
{
	int massive [m*n];

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%12.d ", massive[i + j]);
		}
		printf("\n");
	}
	return 0;
}