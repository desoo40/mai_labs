/*
#include <stdio.h>
int a,b,c;
int main(void) {
	b=a-((a%10)*10);
	a=a%10;	
	while(a%10!=0) {
		b=a-((a%10)*10);
		if(c==b) {
			a=0;
			printf("Est6 odinakovie \n");
		}
		else  a=a%10;
		c=b;
	}
	printf("Ni4e net \n");
}
*/

#include <stdio.h>

int main(void)
{
	int number = 0;
	int residue = 11;
	int temp = 0;

	scanf("%d", &number);

	while (number != 0) {
		temp = residue;
		residue = number % 10;
		number /= 10;
		if (residue == temp) {
			number = 23;
			printf("Number has similar next step digits\n");
			break;
		}
	}
	if (number != 23) {
		printf("Oops... There is no similar digits =(\n");
	}
	return 0;
}
