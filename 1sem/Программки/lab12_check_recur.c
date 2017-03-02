#include "stdio.h"

int tpiple_incremet(int);

int main(void)
{
    int before_increment;
    int after_increment;
    
    scanf("%d", &before_increment);

    after_increment =  tpiple_incremet(before_increment);

    printf("%d\n", after_increment);

    return 0;
}

int tpiple_incremet(int number)
{   
  
    int after_increment = ((number + 3) % 10);
    if (number >= 10){
        return 10 * tpiple_incremet(number / 10) + after_increment;
    }
    return after_increment;
}
