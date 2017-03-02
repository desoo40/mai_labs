/*
Задача 12
На вход в первой строке подаётся число n -- количество тестов для программы.
Далее следует n строк, в каждой из которых первое число -- это сумма имеющихся в наличии денег,
а все последующие числа (пока не встретится -1) -- это цены товаров,
которые необходимо приобрести. Учесть, что в целевом штате НДС = 8%.
Все числа-цены имеют два знака после точки и не превосходят ста тысяч.
Если денег по условиям теста достаточно, вывести "Enough money".
Иначе, если не хватает $K, вывести "$K shortage", причём K вывести с 2 знаками после точки и знаком '$'.
Примеры
Входные данные  Результат работы
3
10.50 7.60 1.26 3.49 -1
15.75 6.00 3.98 -1
21.00 5.25 5.75 4.76 3.98 1.50 -1
$2.84 shortage
Enough money
$1.94 shortage

*/

#include "stdio.h"
int main(void)
{
    long long all_lines;
    double cash_we_have;
    double cash_need_to_pay;
    double cost_of_one_thing;

    scanf("%lld", &all_lines);

    for (int number_of_line = 0; number_of_line < all_lines; ++number_of_line) {
        scanf("%lf", &cash_we_have);
        cash_need_to_pay = 0.0f;
        while (scanf("%lf", &cost_of_one_thing) == 1 && cost_of_one_thing != -1.0) {
            cash_need_to_pay += cost_of_one_thing;
        }
        cash_need_to_pay *= 1.08f;
        if (cash_we_have - cash_need_to_pay >= 0.0f) {
            printf("Enough money\n");
        } else {
            printf("$%.2lf shortage\n", cash_need_to_pay - cash_we_have);
        }
    }
    return 0;
}