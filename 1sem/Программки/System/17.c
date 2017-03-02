/*
Задача 17

Суммировать цифры неотрицательного числа до тех пор,
пока сумма цифр не станет одноциферной (например, для числа 38 имеем 3 + 8 = 11,
а затем 1 + 1 = 2. Ответ -- 2).
Число на входе не превосходит 5 млрд.
*/


#include <stdio.h>

int main()
{
    long long number;
    long long sum = 10;
    
    scanf("%lld", &number);
    while (sum >= 10) {
        sum = 0;
        while (number / 10) {
            sum += number % 10;
            number /= 10;
        }
        sum += number % 10;
        number = sum;
    }
    printf("%lld\n", sum);
    return 0;
}