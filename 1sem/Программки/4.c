/*Задача 4

На вход подаётся набор слов "zero", "one", "two", "three", "four", разделённых произвольным количеством пробельных знаков,
и обозначающих соответствующие цифры неотрицательного числа, записанного в пятеричной системе счисления.
Вывести десятичное число, соответствующее поступившей на вход пятеричной записи.
Гарантируется, что результирующее десятичное число не будет превосходить 2 млрд
Следует обратить внимание на то, что во входном потоке могут встречаться только оговоренные слова (и именно в таком их написании) или пробельные знаки.
Иными словами, ввод не может быть некорректным, и это существенно упрощает решение задачи.
*/

typedef enum {
    BEGIN,
    TWO_OR_THREE,
    SCROLLING
} State;

#include "stdio.h"
#include "math.h"

int main(void)
{
    int c;
    State state = BEGIN;
    long long temp;
    long long number_of_base5 = 0LL;
    int decimal = 0;
    int i = 1;

    while ((c = getchar()) != EOF) {
        switch (state) {
            case BEGIN:
                if (c == ' ') {
                    state = BEGIN;
                    break;
                } else if (c == 'z') {
                    number_of_base5 *= 10LL;
                    state = SCROLLING;
                    break;
                } else if (c == 'o') {
                    number_of_base5 *= 10LL;
                    number_of_base5 += 1LL;
                    state = SCROLLING;
                    break;
                } else if (c == 'f') {
                    number_of_base5 *= 10LL;
                    number_of_base5 += 4LL;
                    state = SCROLLING;
                    break;
                } else if (c == 't') {
                    state = TWO_OR_THREE;
                    break;
                }
                break;

            case TWO_OR_THREE:
                if (c == 'w') {
                    number_of_base5 *= 10LL;
                    number_of_base5 += 2LL;
                    state = SCROLLING;
                    break;
                } else if (c == 'h') {
                    number_of_base5 *= 10LL;
                    number_of_base5 += 3LL;
                    state = SCROLLING;
                    break;
                }
                break;

            case SCROLLING:
                if (c == ' ') {
                    state = BEGIN;
                } else {
                    state = SCROLLING;
                }
                break;
        }
    }
    printf("%lld\n", number_of_base5 );
    temp = number_of_base5;
    while (temp != 0) {
        temp /= 10;
        ++i;
    }
printf("%d\n", i );
    for (int n = 0; n < i ; ++i) {
        decimal *= 5;
        decimal += number_of_base5 % 10;
    }
    printf("%d\n", decimal);
    return 0;
}
// 234 = 4 + 3*5 + 2*25 = 4 + 5(3 + 5*2)