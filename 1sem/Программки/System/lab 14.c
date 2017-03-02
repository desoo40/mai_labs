#include "stdio.h"
enum { maxn = 100 };

int main(void)
{
    int massive[maxn][maxn];
    int n;

    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != n; ++j){
            scanf("%d", &m[i][j]);
        }
    }
    return 0;
}