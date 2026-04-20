#include <stdio.h>
#include <math.h>

int main() {
    float x[6][2] = {
        {0.10, 0.10},
        {0.20, 0.20},
        {0.30, 0.10},
        {0.50, 0.30},
        {0.40, 0.40},
        {0.20, 0.40}
    };

    float w[2][2] = {
        {0.5, 0.5},
        {0.5, 0.5}
    };

    float D[2];
    float LR = 0.6;

    int i, j, k, epoch;

    for (epoch = 0; epoch < 10; epoch++) {
        printf("\nEpoch %d\n", epoch+1);

        for (k = 0; k < 6; k++) {
            // Hitung jarak
            for (j = 0; j < 2; j++) {
                D[j] = 0;
                for (i = 0; i < 2; i++) {
                    D[j] += pow(w[j][i] - x[k][i], 2);
                }
            }

            // Tentukan pemenang
            int winner = (D[0] < D[1]) ? 0 : 1;

            // Update bobot
            for (i = 0; i < 2; i++) {
                w[winner][i] = w[winner][i] + LR * (x[k][i] - w[winner][i]);
            }
        }

        // Tampilkan bobot tiap epoch
        printf("W1 = (%.4f, %.4f)\n", w[0][0], w[0][1]);
        printf("W2 = (%.4f, %.4f)\n", w[1][0], w[1][1]);

        // Update learning rate
        LR = 0.5 * LR;
    }

    // Mapping cluster
    printf("\nHasil Clustering:\n");

    for (k = 0; k < 6; k++) {
        for (j = 0; j < 2; j++) {
            D[j] = 0;
            for (i = 0; i < 2; i++) {
                D[j] += pow(w[j][i] - x[k][i], 2);
            }
        }
        int winner = (D[0] < D[1]) ? 0 : 1;
        int cluster = winner + 1;

        float kecil = sqrt(D[winner]);
        float besar = sqrt(D[1 - winner]);

    printf("Data (%.2f, %.2f) -> Cluster %d (Euc: %.4f > %.4f)\n",
           x[k][0], x[k][1], cluster, kecil, besar);
    }
    return 0;
}
