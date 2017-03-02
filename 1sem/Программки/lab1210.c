#include <stdio.h>

int sign(int x) 
{
	return x > 0 ? 1 : -1;
}

int swap_digits(int number)
{
	int accum = 1;
	int prelast;
	int second;

	int sign_value = sign(number);
	number *= sign_value;

	while (100 * accum <= number) {
		accum *= 10;
	}

	prelast = (number % 100) / 10;
	second = (number / accum) % 10;

	return sign_value * (number + (accum - 10) * (prelast - second));
}

int main ()
{
	int number;
	while (scanf ("%d", &number) == 1) {
		if (number / 10) {
			printf("%d\n", swap_digits(number));
		}
		else {
			printf("I CAN'T WORK WITH THIS NUMBER!!!!\n");
		}
	}
	return 0;
}
