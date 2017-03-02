#include "stdio.h"
#include "stdbool.h"

bool is_it_good_password(int x, int y, int z, int u)
{
    if (x >= 8 && y > 0 && z > 0 && u > 0) {
        return true;
    } else {
        return false;
    }
}

int main(void)
{
    int c;
    int how_many_signs;
    int is_digit = 0;
    int is_letter = 0;
    int is_letter_title = 0;
    bool ochka;
    
    for (how_many_signs = 1; (c = getchar()) != EOF ; ++how_many_signs) {
        if (c == ' ' || c == '/' || ((c >= '0' && c <= '9') && how_many_signs < 2) || how_many_signs > 12) {
            how_many_signs = 0;
            break;
        } else if (c >= '0' && c <= '9') {
            ++is_digit;
        } else if (c >= 'a' && c <= 'z') {
            ++is_letter;
        } else if (c >= 'A' && c <= 'Z') {
            ++is_letter_title;
        }
    }
    
    ochka = is_it_good_password(how_many_signs, is_digit, is_letter, is_letter_title);
    
    if (ochka == true) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}
