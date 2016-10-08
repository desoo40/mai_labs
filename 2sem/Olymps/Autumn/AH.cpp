#include <stdio.h>

int main(void)
{

	int size = 0;

	scanf("%d", &size);

	int A[size][size];
	int B[size][size];

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			scanf("%d", &B[i][j]);
		}
	}

	long long sum = 0;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			sum += A[i][j] * B[j][i];

			if (i != j)
				sum += B[j][i] * A[i][j];
		}
	}

	printf("%lld\n", sum);

	return 0;
}