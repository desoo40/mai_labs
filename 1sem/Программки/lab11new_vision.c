#include "stdio.h"
#include "math.h"

int main ()
{
	int state = 1;
	char c;
	double number = 0;
	double so_number = 0;
	int quality = 0;

	while ((c = getchar()) != EOF)
		switch (state) {
			case 1:
				if (c >= '0' && c <= '9') {
					number *= 10;
					number += (c - '0');
					state = 2;
				}
				else {
					if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
						state = 1;
					}
					else {
						if (c == '.') {
							state = 8;
						}
						else {
						state = 5;
						}
					}	
				}
				break;

			case 2:
				if (c >= '0' && c <= '9') {
					number *= 10;
					number += (c - '0');
					state = 2;
				}	
				else {
					if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
						number = 0;
						state = 1;
					}
					else {
						if (c == '.'){
							state = 3;
						}
						else {
							if (c == 'i'){
								state = 4;
							}
							else {
								state = 5;
							}
						}
					}
				}
				break;

			case 3:
				if (c >= '0' && c <= '9') {				
					so_number *= 10;
					so_number += (c - '0');
					++quality;
					state = 3;
				}	
				else {
					if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
						so_number = 0;
						number = 0;
						state = 1;
						quality = 0;
					}
					else {
						if (c == 'i') {
							state = 4;
						}
						else {
							state = 5;
						}
					}
				}
				break;

			case 4:
				if (c == 'n') {
					state = 7;
				}
				else {
					if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
						so_number = 0;
						number = 0;
						state = 1;
						quality = 0;
					}
					else {
							state = 5;
						}
					}
					break;

			case 5:
				if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
					number = 0;
					so_number = 0;
					quality = 0;
					state = 1;
				}	
				else {
					state = 5; 
				}
				break;

			case 6:
				if (c == '.') {
					state = 3;
				}	
				else {
					if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
						state = 1;
					}
					else {
						state =5;
					}
				}
			case 7:
				if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
					printf("%lfmm\n", (number + so_number*pow(0.1, quality)) * 25.4);
					number = 0;
					so_number = 0;
					quality = 0;
					state = 1;
				}	
				else {
					state = 5;
				}
			case 8:
				if (c >= '0' && c <= '9') {
					so_number *= 10;
					so_number += (c - '0');
					++quality;
					state = 3;
				}
				else {
					if (c == 'i') {
						state = 5;
					}
					else {
						if (c == ' ' || c == '\n' || c == '\t' || c == ',') {
							state = 1;
						}	 	
						
					}
				}
			}
	return 0;			
}
