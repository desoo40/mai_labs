#include <stdio.h>

int main()
{
    int c;
    long long decimal = 0LL;

    while ((c = getchar()) != EOF) {
        decimal *= 2LL;
        decimal += (c - '0');
    }
    printf("%lld\n", decimal);
    return 0;
}
