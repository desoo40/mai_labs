#include "stdio.h"

typedef enum {
    SPACE,
    NUMBER,
    POINT,
    OTHER
} State;

int is_space(int c)
{
    return (c == ' ') || (c == '\n') || (c == '\t') || (c == ',');
}

int is_digit(int c)
{
    return (c >= '0') && (c <= '9');
}

int main()
{
    State state = SPACE;
    int c;
    int quantity = 0;
    int num = 0;
    int cnt_of_nums = 0;
    
    while ((c = getchar()) != EOF) {
        switch (state) {
            case SPACE:
                if (is_digit(c)) {
                    state = NUMBER;
                    num = c - '0';
                    
                } else if (!is_space(c)) {
                    state = OTHER;
                }
                break;
            case NUMBER:
                if (is_digit(c)) {
                    num *= 10;
                    num += c - '0';
                    if (num > 255) {
                        state = OTHER;
                    }
                    
                } else if (is_space(c)) {
                    state = SPACE;
                    if (cnt_of_nums == 3) {
                        ++quantity;
                    }
                    
                    cnt_of_nums = 0;
                } else if (c == '.') {
                    state = POINT;
                    ++cnt_of_nums;
                } else {
                    state = OTHER;
                }
                break;
            case POINT:
                if (is_digit(c)) {
                    state = NUMBER;
                    num = c - '0';
                } else if (is_space(c)) {
                    state = SPACE;
                    cnt_of_nums = 0;
                } else {
                    state = OTHER;
                }
                break;
            case OTHER:
                if (is_space(c)) {
                    state = SPACE;
                    cnt_of_nums = 0;
                }
                break;
        }
    }
    printf("%d\n", quantity);
    return 0;