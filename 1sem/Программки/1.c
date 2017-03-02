#include "stdio.h"

int main ()
{
    int number;
    int checking;
    int how_many_is_simmular = 0;
    scanf("%d", &number);

    while (scanf("%d", &checking) == 1) {
        if (checking == number) {
            ++how_many_is_simmular;
        }
    }
    printf("%d\n", how_many_is_simmular);
    return 0;
}