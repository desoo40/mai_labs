#include "stdio.h"

typedef enum {
	SPACE,
	NUMBER,
	POINT,
	OTHER
} State;

int is_space(int c) {
	return (c == ' ') || (c == '\n') || (c == '\t') || (c == ','); 
}

int is_digit(int c) {
	return (c >= 0) && (c <= 9);
}

int main ()
{
	State state = SPACE;
	int c;
	int quantity = 0;
	int num = 0;
	int cnt_of_nums = 0;

	while ((c = getchar()) != EOF) {
		switch (state) {
			case SPACE:
				if (is_digit(c)) {
					state = NUMBER;
				}
				else if (!is_space(c)) {
					state = OTHER;
				}
				break;
			case NUMBER:
				if (is_digit(c)) {
					num *= 10;
					num += c - '0';
					if (num > 255) {
						state = OTHER;
					}
				}
				else if (is_space(c)) {
					state = SPACE;
				}
				else if (c == '.') {
					state
				}
				else {
					state = O
				}
				break;

		}
	}
}