#include "stdio.h"
#define N 1000

int main ()
{
	char c;
	char ms[N];
	int state = 1;
	int q = 0;

	while ((c = getchar ()) != EOF) {

		switch (state) {
			case 1:
				if (c >= '1' && c <= '9') {
					ms[q] = c;
					state = 2;
					++q;
				}	
				else {
					if (c == ' ') {
						state = 1;
					}
					else {
						state = 5;
					}	
				}
				break;

			case 2:
				if (c >= '0' && c <= '9') {
					ms [q] = c;
					++q;
					state = 2;
				}	
				else {
					if (c == ' ' || c == '\n' ) {
						if (q > 3) { 
							char temp = ms[1];
							ms[1] = ms[q - 2];
							ms[q - 2] = temp;

							for (int i = 0; i < q; ++i)
							{
								printf("%c", ms[i]);
							}
							printf("\n");

							q = 0;
							state = 1;

						}	
						else {
							q = 0;
							state = 1;
						} 		
					} 
					else {
						state = 5; 
					} 
				}
				break;
					
			case 5:
				if (c == ' ' || c == '\n') {
					state = 1;
					q = 0;
				}	
				else {
					state = 5;
				}
				break;
		}
	}
	return 0;
}