/*
Задача 1

На вход подаётся число N, а за ним -- числовая последовательность произвольной длины.
Подсчитать количество вхождений числа N в последовательность.
Все числа со входного потока целые и по модулю не превосходят 4 млрд.
*/
#include <stdio.h>

int main()
{
    long long number;
    long long checking;
    long long how_many_is_similar = 0;
    scanf("%lld", &number);

    while (scanf("%lld", &checking) == 1) {
        if (checking == number) {
            ++how_many_is_similar;
        }
    }

    printf("%lld\n", how_many_is_similar);
    return 0;
}
