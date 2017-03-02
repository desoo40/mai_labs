#include "stdio.h"

int main(void)
{
    int fund;
    scanf("%d", &fund);
    int num_of_line = 1;
    if (fund % 2 == 1) {
        while (num_of_line <= fund - (num_of_line - 1)) {
            for (int n = 1; n <= (fund - ((num_of_line * 2) - 1)) / 2; ++n) {
                printf(" ");
            }
            for (int i = 1; i <= num_of_line * 2 - 1; ++i) {
                printf("*");
            }
            printf("\n");
            ++num_of_line;
        }
    }
    return 0;
}