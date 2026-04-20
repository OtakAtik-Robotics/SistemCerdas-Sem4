#include <stdio.h>

void main() {
    int w1 = 2, w2=2, t=2;
    int x1, x2, y, out;
    printf("Operasi OR\n");
    printf("Input x1=");
    scanf("%d", &x1);
    printf("Input x2=");
    scanf("d", &x2); y = w1 * x1 + w2 * x2; 
    if (y >= t) out = 1;
    else out =0;
    printf("Output=%d\n", out);
}