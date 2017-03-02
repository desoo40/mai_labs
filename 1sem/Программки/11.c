#include "stdio.h"

int between_the_centers(int x1, int x2, int y1, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main(void)
{
    int x1;
    int x2;
    int r1;
    int y1;
    int y2;
    int r2;
    
    scanf("%d", &x1);
    scanf("%d", &y1);
    scanf("%d", &r1);
    scanf("%d", &x2);
    scanf("%d", &y2);
    scanf("%d", &r2);
    
    if ((r1 + r2) * (r1 + r2) > between_the_centers(x1, x2, y1, y2)) {
        printf("Intersection\n");
    } else if ((r1 + r2) * (r1 + r2) < between_the_centers(x1, x2, y1, y2)) {
        printf("No intersection\n");
    } else {
        printf("Tangential\n");
    }
    return 0;
}
