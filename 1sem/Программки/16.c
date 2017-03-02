#include <stdio.h>

int main(void)
{
    int ostatok = 0;
    int c;

    while ((c = getchar ()) != '\n') {
        ostatok += (c - '0');
        ostatok %= 3;
    }

    if (ostatok == 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}