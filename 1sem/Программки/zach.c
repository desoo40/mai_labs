#include "stdio.h"

int main ()
{
	int line;
	scanf ("%d", &line);

	if (line > 0 && line <= 10) {
	
		for (int i = 1; i <= line ; ++i)
			{
				printf("*");
				if (i == 1 || i == line) {
					for (int k = 1; k <= line - 1; ++k)
					{
						printf("*");
					}
				}
				else {
					for (int l = 1; l < line - 1; ++l)
					{
						printf(" ");
					}
					printf("*");
				
				}
				printf("\n");
			}
	}
	else {
		printf("Ohh... Sorry... I can't... Please enter another digit\n");
	}	
	getchar ();
	return 0;
}
