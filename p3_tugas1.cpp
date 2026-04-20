#include <stdio.h>
#include <stdlib.h>

#define EPOCH 20
#define LR 0.1

int step(float x){
    if(x >= 0) return 1;
    else return 0;
}

void train_perceptron(int T[4], char *nama){

    int x[3][4] = {
        {0,0,1,1},   // x1
        {0,1,0,1},   // x2
        {1,1,1,1}    // bias
    };

    float w[3] = {0.2, -0.1, 0.1};
    int i,j,out,ERR,total_err;
    float O;

    printf("\n=== Training %s ===\n", nama);

    for(i=0;i<EPOCH;i++){
        total_err = 0;

        for(j=0;j<4;j++){
            O = x[0][j]*w[0] + x[1][j]*w[1] + x[2][j]*w[2];
            out = step(O);

            ERR = T[j] - out;
            total_err += abs(ERR);

            w[0] += LR * x[0][j] * ERR;
            w[1] += LR * x[1][j] * ERR;
            w[2] += LR * x[2][j] * ERR;
        }

        printf("Epoch %d - Total Error: %d\n", i+1, total_err);

        if(total_err == 0) break;
    }

    printf("\nHasil Testing %s:\n", nama);
    for(j=0;j<4;j++){
        O = x[0][j]*w[0] + x[1][j]*w[1] + x[2][j]*w[2];
        out = step(O);
        printf("%d %s %d = %d\n", x[0][j], nama, x[1][j], out);
    }
}

int main(){

    int T_and[4] = {0,0,0,1};
    int T_or[4]  = {0,1,1,1};

    train_perceptron(T_and, "AND");
    train_perceptron(T_or, "OR");

    return 0;
}