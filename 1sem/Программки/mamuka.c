#include <stdio.h>


int main ()
{
	int a;
	int b;
int p;
		p = 1;
	printf("Base:");
	scanf ("%d", &a);
	printf("Stepen:");
	scanf ("%d", &b);

	for (int i = 0; i <= b; ++i)
	{	
		
		printf("%d v stepeni %d = %d\n",a, i, (i != 0 ? p * a : 1) );
		p = p * a;
	}
}
