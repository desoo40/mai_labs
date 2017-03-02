#include "stdio.h"
#include "math.h"

void reset(char *c, int *state, double *number, double *so_number, int *quality)
{
	*state = 1;
	*number = 0;
	*so_number = 0;
	*quality = 0;
	return;
}

void accum(char *c, int *state, double *number)
{
	*(number) *= 10;
	*(number) += (*c - '0');
	*state = 2;
	return;
}

int main()
{
	int state = 1;
	char c;
	double number = 0;
	double so_number = 0;
	int quality = 0;


	c = 0;
	while (c != EOF) 
	{
		c = getchar();
		switch (state) {
		case 1:6665
			if (c >= '1' && c <= '9') 
			{
				accum(&c, &state, &number);
			}
			else 
			{
				reset(&c, &state, &number, &so_number, &quality);
				while (c != ' ' || c != '\n')
				{
					c = getchar();
					if (c == ' ' || c == '\n') break;
				}
			}

			break;

		case 2:
			if (c >= '0' && c <= '9')
			{
				accum(&c, &state, &number);
			}
			else if (c == 'i') 
			{
				state = 4;
			}
			else if (c == '.') 
			{
				state = 3;
			}	
			else 
			{
				reset(&c, &state, &number, &so_number, &quality);
			}

			break;

		case 3:
			if (c >= '0' && c <= '9') 
			{
				accum(&c, &state, &number);
				++quality;
				state = 3;
			}
			else if (c == 'i') 
			{
				state = 4;
			}
			else 
			{
				reset(&c, &state, &number, &so_number, &quality);
			}

			break;

		case 4:
			if (c == 'n') 
			{
				state = 5;
			}
			else 
			{
				reset(&c, &state, &number, &so_number, &quality);
			}

			break;

		case 5:
			if (c == ' ' || c == '\n') 
			{
				printf("%.2lfmm\n", (number + so_number*pow(0.1, quality))*25.4);
				number = 0;
				so_number = 0;
				quality = 0;
				state = 1;
			}
			else 
			{
				printf("\n");
				reset(&c, &state, &number, &so_number, &quality);
			}

			break;
		}
	}

	getchar();

	return 0;
}


/*
234234in

*/