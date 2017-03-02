#include "stdio.h"
enum {max_n = 400};

int diagonal_coefficient(int b, int y)
{
    if (b == 0) {
        return 0;
    } else {
        return b % 2 != 0 ? y - 1 : y;
    }
}

int sign(int n)
{
    return n % 2 == 0 ? 1 : -1;
}

int main(void)
{
    int tests;
    int max_n_in_tests;
    int massive[max_n];
    int n;
    int current_element;
    int temp;
    int y = 0;

    scanf("%d %d %d", &tests, &max_n_in_tests, &n);

    for (int num_of_element = 0; num_of_element != n * n; ++num_of_element) {
            scanf("%d", &(massive[num_of_element]));
    }

    current_element = n * (n - 1);

    for (int diagonal = 0; diagonal < (n * 2) - 1; ++diagonal) {

        if (diagonal % 2 != 0) {
            ++y;
        }

        current_element += -1 * sign(diagonal) * (n * y + diagonal_coefficient(diagonal, y));
        temp = current_element;
        
        for (int i = 0; i < n - y; ++i) {
            current_element = temp - (n - 1) * i * sign(diagonal);
            printf("%d ", massive[current_element]);
        }
    }

    printf("\n");
    return 0;
}