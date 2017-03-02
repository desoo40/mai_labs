#include <stdio.h>

int main(void)
{
    int accum = 0;
    int sign = 1;
    int c;
    
    while ((c = getchar()) != EOF) {
        accum += sign * (c - '0');
        sign *= -1;
    }
    if (accum % 11 == 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}