#include "stdio.h"

int main(void)
{
    long long lines = 0LL;
    double cash_we_have = 0.0;
    double cash_need_to_pay = 0.0;
    double cost_of_one_thing = 0.0;
    
    scanf("%lld", &lines);
    
    for (long long num_of_line = 0LL; num_of_line < lines; ++num_of_line) {
        
        scanf("%lf", &cash_we_have);
        cash_need_to_pay = 0.0;
        
        while ((scanf("%lf", &cost_of_one_thing)) == 1 && cost_of_one_thing != -1.0) {
            
            cash_need_to_pay += cost_of_one_thing;
        }
        
        cash_need_to_pay *= 1.08;
        
        if (cash_we_have >= cash_need_to_pay) {
            printf("\nEnough money\n");
        } else {
            printf("\n$%.2lf shortage\n", cash_need_to_pay - cash_we_have);
        }
    }
    return 0;
}