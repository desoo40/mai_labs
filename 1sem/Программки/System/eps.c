#include <stdio.h>
int main(void) {
	int a,b,c;
	scanf("%d",&a);
	c=a-((a%10)*10);
	a=a%10;
	while(a!=0) {
		if((a%10)!=0) {
			b=a-((a%10)*10);
			if(c==b) {
				printf("Est odinakovie \n");
				break;
			}
			else {
				c=b;
				b=0;
			}
		}
		else {
			if(a==c) {
				printf("Est odinakovie \n");
			}
			else {
				printf("Vse Raznie \n");
			a=0;
			}
		}
	}
}