#include "stdio.h"
#include "math.h"

int main ()
{	
	int accum = 0;
	int c;
	while ((c = getchar()) != '\n' ) {
		++accum;
	}
	printf("%d\n", accum );
	return 0;
}