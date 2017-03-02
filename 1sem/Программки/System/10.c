#include "stdio.h"

int main(void)
{
    int high;
    scanf("%d", &high);
    
    for (int num_of_line = 1; num_of_line <= high; ++num_of_line) {
        for (int spaces_before_star = 1; spaces_before_star != num_of_line; ++spaces_before_star) {
            printf(" ");
        }
        if (num_of_line != high) {
            printf("*");
        }
        for (int spaces_between_stars = 1; spaces_between_stars <= high * 2 - num_of_line * 2 - 1; ++spaces_between_stars) {
            printf(" ");
        }
        printf("*\n");
    }
    return 0;
}
