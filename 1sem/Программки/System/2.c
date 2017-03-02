/*
Задача 2

На вход подаётся число N, а за ним -- числовая последовательность произвольной длины.
Подсчитать количество чисел в последовательности, дающих при делении на 10111 остаток, не превосходящий N.
Все числа со входного потока целые и по модулю не превосходят 4 млрд.
*/
#include <stdio.h>

int main()
{
    long long number;
    long long checking;
    long long how_many_is_good = 0;
    scanf("%lld", &number);
    
    while (scanf("%lld", &checking) == 1) {
        if (checking % 10111 <= number) {
            ++how_many_is_good;
            printf("%lld ", checking);
        }
    }
    
    return 0;
}
