#include <stdio.h>

int main ()
{
	int age; 
	printf ( "How old are you?\n" );
	scanf ("%d", &age);
	if ( age < 100 ) {
		printf ("Little pig!\n");
	}
	else if ( age == 100) {
	printf ("YOU ARE FUCKING LIER\n");
	}
	else {
		printf("GOD...\n");
	}
	return 0;
}
