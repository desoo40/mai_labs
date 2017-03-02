#include <stdio.h>

int main(void)
{
    int residue = 0;
    int c;
    
    while ((c = getchar()) != EOF && c >= '0' && c <= '9') {
        residue += (c - '0');
        residue %= 3;
    }
    
    if (residue == 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}