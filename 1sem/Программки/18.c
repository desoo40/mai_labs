#include <stdio.h>
#include <math.h>

int main (void)
{
    int number;
    int sum = 10;

    scanf("%d", &number);
    if (number % 10 == 0) {
        sum = 1;
    }
    do
       {
           sum += number % 10
       } while (sum >= 10);   


    printf("%d\n", sum);
    return 0;
}