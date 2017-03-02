/*
Задача 13

На вход подаётся целое положительное число N, не превосходящее миллиарда.
Вывести через пробел числа от 1 до N. При этом вместо чисел, кратных трём, выводить "A", а вместо чисел, кратных пяти —- "B".
Если число кратно и 3, и 5, то программа должна выводить вместо этого числа "AB".
*/
#include <stdio.h>

int main()
{
    int digit;
    
    scanf("%d", &digit);
    for (int number_of_sign = 1; number_of_sign <= digit; ++number_of_sign) {
        if (number_of_sign % 15 == 0) {
            printf("AB ");
        } else if (number_of_sign % 3 == 0) {
            printf("A ");
        } else if (number_of_sign % 5 == 0) {
            printf("B ");
        } else {
            printf("%d ", number_of_sign);
        }
    }
    printf("\n");
    return 0;
}
