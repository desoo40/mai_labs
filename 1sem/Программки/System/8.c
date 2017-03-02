/*
Задача 8

На вход подаётся нечётное целое число от 1 до 99 включительно.
Нарисовать с помощью знаков ' ' и '*' (пробел и звезда)
наклонённый квадрат с диагональю, равной введённому числу,
согласно приведённому примеру.
Примеры

  5

  *
 ***
*****
 ***
  *
*/

#include "stdio.h"

int main(void)
{
    int diagonal;
    scanf("%d", &diagonal);
    int num_of_line = 1;
    if (diagonal % 2 == 1) {
        while (num_of_line <= (diagonal + 1) / 2) {
            for (int i = 0; i < (diagonal - ((num_of_line * 2) - 1)) / 2; ++i) {
                printf(" ");
            }
            for (int i = 0; i < num_of_line * 2 - 1; ++i) {
                printf("*");
            }
            printf("\n");
            ++num_of_line;
        }
        num_of_line -= 2;
        while (num_of_line != 0) {
            for (int i = 0; i < (diagonal - ((num_of_line * 2) - 1)) / 2; ++i) {
                printf(" ");
            }
            for (int i = 0; i < num_of_line * 2 - 1; ++i) {
                printf("*");
            }
            printf("\n");
            --num_of_line;
        }
    }
    return 0;
}
