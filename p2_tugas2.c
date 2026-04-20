#include <stdio.h>

void main() {
    int w1 =1, w2=1, w3=1, t=1, i=4;
    int x1, x2, x3, y, ol, o2, o3, zl, z2;
    do {
        printf("Operasi OR\n");
        printf("Input x1=");
        scanf_s("%d", &x1);
        printf("Input x2=");
        scanf_s("%d", &x2);
        printf("Input x3=");
        scanf_s("%d", &x3);

        y = w1 * x1 + w2 * x2 + w3 * x3;
        if (y > t) y = 1;
        else y = 0;
        printf("Outout=%d\n\n", y);
        i--;
    } while (i > 0);
}