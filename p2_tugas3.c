#include <stdio.h>

int main() {
int x1, x2, x3, z1, z2, z3, z4, z5, y;
int t = 2;

int w1 = 2, w2 = -1, w3 = -1, w4 = 2;
int w5 = 2, w6 = -1, w7 = -1, w8 = 2;
int o1, o2, o3, o4, o5, o6;

printf("Tabel Kebenaran XOR 3 Input (JST)\n");
printf("x1 x2 x3 | y\n");
printf("----------------- \n");

for (x1 = 0; x1 <= 1; x1++) {
    for (x2 = 0; x2 <= 1; x2++) {
        for (x3 = 0; x3 <= 1; x3++) {
            // ===== XOR x1 dan x2 =====
            o1 = w1 * x1 + w2 * x2;
            z1 = (o1 >= t) ? 1 : 0;

            o2 = w3 * x1 + w4 * x2;
            z2 = (o2 >= t) ? 1 : 0;

            o3 = 2 * z1 + 2 * z2;
            z3 = (o3 >= t) ? 1 : 0;

            // ===== XOR hasil dengan x3 =====
            o4 = w5 * z3 + w6 * x3;
            z4 = (o4 >= t) ? 1 : 0;

            o5 = w7 * z3 + w8 * x3;
            z5 = (o5 >= t) ? 1 : 0;

            o6 = 2 * z4 + 2 * z5;
            y = (o6 >= t) ? 1 : 0;

            printf("%d %d %d | %d\n", x1, x2, x3, y);
            }
        }
    }
    return 0;
}