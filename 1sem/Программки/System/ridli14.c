#include <stdio.h>


inline int min(int x, int y)
{
    return (x < y) ? x : y;
}


int main(void)
{
    int n = 0;
    scanf("%d", &n);
    
    int matrix[n][n] = { { 0 } };
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &(matrix[i][j]));
        }
    }
    
    int dir = 0, bound = 0;
    for (int k = 0; k < 2 * n - 1; ++k) {
        dir = (k % 2) ? (-1) : 1;
        bound = min(k, 2 * n - 2 - k);
        
        for (int p = -bound; p <= bound; p += 2) {
            printf("%d ", matrix[n - 1 - (k + dir * p) / 2][n - 1 - (k - dir * p) / 2]);
        }
    }
    printf("\n");
    
    return 0;
}
