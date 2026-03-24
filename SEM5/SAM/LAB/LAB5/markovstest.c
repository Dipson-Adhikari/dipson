#include <stdio.h>

int main() {
    
    double T[2][2] = {
        {0.9, 0.1},
        {0.2, 0.8}
    };

    double result[2][2] = {
        {1, 0},
        {0, 1}
    };

    double temp[2][2];

    
    int N;
    printf("\nEnter the number of steps(N):\n");
    scanf("%d",&N);

    for(int step = 0; step < N; step++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                temp[i][j] = 0;
                for(int k = 0; k < 2; k++) {
                    temp[i][j] += result[i][k] * T[k][j];
                }
            }
        }

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                result[i][j] = temp[i][j];
    }

    printf("Q1)Coke after 2 steps = %.3lf\n", result[1][0]);

    result[0][0] = 1; result[0][1] = 0;
    result[1][0] = 0; result[1][1] = 1;
    N = 3;
    for(int step = 0; step < N; step++) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                temp[i][j] = 0;
                for(int k = 0; k < 2; k++) {
                    temp[i][j] += result[i][k] * T[k][j];
                }
            }
        }

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                result[i][j] = temp[i][j];
    }

    printf("Q2)Pepsi after 3 steps = %.3lf\n", result[0][1]);

    double P0[2] = {0.6, 0.4};
    double P3[2] = {0, 0};

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            P3[i] += P0[j] * result[j][i];
        }
    }

    printf("\nQ3)fter 3 steps:\n");
    printf("Coke  = %.4lf\n", P3[0]);
    printf("Pepsi = %.4lf\n", P3[1]);

    return 0;
}