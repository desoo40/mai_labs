#include "stdio.h"

int main(void)
{
    int decimal = 0;
    int digit;
    
    while ((scanf("%d", &digit)) == 1) {
        if (digit % 5 == 0) {
            decimal *= 50;
            decimal += digit;
        }
    }
    printf("%d\n", decimal);
    return 0;
}