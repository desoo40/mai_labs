#include <stdio.h>

int main ()
{
 	int n;
 	int sum;
 	sum = 0;
 	scanf ("%d", &n);

 	for (int i = 1; i <= n; i = i + 2)
 	{
 		sum = sum + i;
 	}
 	
 	printf("%d\n", sum );
 }
