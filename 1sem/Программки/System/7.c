#include "stdio.h"
#include "stdbool.h"

bool is_it_good_password(int x, bool y, bool u)
{
    if (x >= 8 && y == true && u == true) {
        return true;
    } else {
        return false;
    }
}

int main(void)
{
    int c;
    int how_many_signs;
    bool is_digit = false;
    bool is_letter_title = false;
    bool checking;
    
    for (how_many_signs = 1; (c = getchar()) != EOF ; ++how_many_signs) {
        if (c == '\n') {
            how_many_signs -= 1;
            break;
        } else if (c == ' ' || c == '/' || ((c >= '0' && c <= '9') && how_many_signs < 1) || how_many_signs > 12) {
            how_many_signs = 0;
            break;
        } else if (c >= '0' && c <= '9') {
            is_digit = true;
        } else if (c >= 'A' && c <= 'Z') {
            is_letter_title = true;
        }
    }
    
    checking = is_it_good_password(how_many_signs, is_digit, is_letter_title);
    
    if (checking == true) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}