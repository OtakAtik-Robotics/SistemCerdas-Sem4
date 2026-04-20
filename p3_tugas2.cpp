#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INPUT 8      // 7 segment + 1 bias
#define OUTPUT 10
#define DATA 10
#define EPOCH 1000
#define LR 0.1

int main(){

    srand(time(NULL));

    // Data 7 segment (ditambah bias di index terakhir)
    int x[DATA][INPUT] = {
        {1,1,1,1,1,1,0,1}, //0
        {0,1,1,0,0,0,0,1}, //1
        {1,1,0,1,1,0,1,1}, //2
        {1,1,1,1,0,0,1,1}, //3
        {0,1,1,0,0,1,1,1}, //4
        {1,0,1,1,0,1,1,1}, //5
        {1,0,1,1,1,1,1,1}, //6
        {1,1,1,0,0,0,0,1}, //7
        {1,1,1,1,1,1,1,1}, //8
        {1,1,1,1,0,1,1,1}  //9
    };

    float w[OUTPUT][INPUT];
    int T[OUTPUT];
    int i,j,k,epoch;
    float O;
    int ERR,total_err;

    // Inisialisasi bobot random kecil
    for(i=0;i<OUTPUT;i++)
        for(j=0;j<INPUT;j++)
            w[i][j] = ((float)rand()/RAND_MAX - 0.5);

    printf("=== Training 7 Segment dengan Bias ===\n");

    for(epoch=0; epoch<EPOCH; epoch++){
        total_err = 0;

        for(i=0;i<DATA;i++){

            // One-hot target
            for(k=0;k<OUTPUT;k++)
                T[k] = (k==i)?1:0;

            for(k=0;k<OUTPUT;k++){

                O = 0;
                for(j=0;j<INPUT;j++)
                    O += x[i][j] * w[k][j];

                int out = (O >= 0)?1:0;
                ERR = T[k] - out;
                total_err += abs(ERR);

                // Update bobot
                for(j=0;j<INPUT;j++)
                    w[k][j] += LR * x[i][j] * ERR;
            }
        }

        printf("Epoch %d - Total Error: %d\n", epoch+1, total_err);

        if(total_err == 0){
            printf("Training selesai pada epoch %d\n", epoch+1);
            break;
        }
    }

    // ================= TESTING =================

    printf("\n=== Testing (Winner Takes All) ===\n");

    for(i=0;i<DATA;i++){

        float max = -9999;
        int pred = -1;

        for(k=0;k<OUTPUT;k++){

            O = 0;
            for(j=0;j<INPUT;j++)
                O += x[i][j] * w[k][j];

            if(O > max){
                max = O;
                pred = k;
            }
        }

        printf("Digit %d dikenali sebagai: %d\n", i, pred);
    }

    return 0;
}