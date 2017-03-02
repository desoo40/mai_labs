#include "stdio.h"
#include "math.h"

typedef enum {
    BEGIN,
    TWO_OR_THREE,
    SCROLLING
} State;

int main(void)
{
    int c;
    State state = BEGIN;
    int decimal = 0;
    int digit = 0;
    
    while ((c = getchar()) != EOF) {
        switch (state) {
            case BEGIN:
                if (c == ' ') {
                    state = BEGIN;
                    break;
                } else if (c == 'z') {
                    decimal *= 5;
                    digit = 0;
                    decimal += digit;
                    state = SCROLLING;
                    break;
                } else if (c == 'o') {
                    decimal *= 5;
                    digit = 1;
                    decimal += digit;
                    state = SCROLLING;
                    break;
                } else if (c == 'f') {
                    decimal *= 5;
                    digit = 4;
                    decimal += digit;
                    state = SCROLLING;
                    break;
                } else if (c == 't') {
                    state = TWO_OR_THREE;
                    break;
                }
                break;
                
            case TWO_OR_THREE:
                if (c == 'w') {
                    decimal *= 5;
                    digit = 2;
                    decimal += digit;
                    state = SCROLLING;
                    break;
                } else if (c == 'h') {
                    decimal *= 5;
                    digit = 3;
                    decimal += digit;
                    state = SCROLLING;
                    break;
                }
                break;
                
            case SCROLLING:
                if (c == ' ') {
                    state = BEGIN;
                } else {
                    state = SCROLLING;
                }
                break;
        }
    }
    printf("%d\n", decimal);
    return 0;
}

