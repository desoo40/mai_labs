/*
Задача 6

На вход подаётся целое число в десятичной системе счисления,
по модулю не превосходящее 1 млрд.
Вывести это число, записанное в девятеричной системе счисления.
*/
#include <stdio.h>
#include <math.h>

int sign(long long x)
{
    return x > 0 ? 1 : -1;
}
int main()
{
    long long decimal;
    long long base9 = 0;
    long long i = 0;
    
    scanf("%lld", &decimal);
    int sign_vaule = sign(decimal);
    decimal *= sign_vaule;
    
    while (decimal / 9) {
        long long temp;
        temp = decimal;
        base9 += (decimal % 9) * pow(10, i);
        ++i;
        temp /= 9;
        decimal = temp;
    }
    base9 += (decimal % 9) * pow(10, i);
    printf("%lld\n", sign_vaule * base9);
    return 0;
}