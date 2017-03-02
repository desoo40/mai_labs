#include "stdio.h"

enum { maxn = 100 };

int main ()
{
	int m[maxn][maxn];
	int n;
	int k;
	int p;

	scanf("%d", &n);
	for (int i = 0; i != n; ++i)
	{
		for (int j = 0; j !=0 ; ++j)
		{
			scanf("%d", &m[i][j]);
			p = j;
		}
		k = i;
	}
	for (int i = 0; i != n; ++i)
	{
		printf("%d ", m[k][p] );
	}
	return 0;
}