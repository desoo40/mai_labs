#include "stdio.h"

int tpiple_incremet(int number)
{   
    int temp = 1;
    int after_increment = 0;
    while (number != 0) {
        after_increment += ((number + 3) % 10) * temp;
        temp *= 10;
        number /= 10;
    }
    return after_increment;
}

int main(void)
{
    int before_increment;
    int after_increment;
 
    scanf("%d", &before_increment);

    after_increment =  tpiple_incremet(before_increment);

    printf("%d\n", after_increment);

    return 0;
}

