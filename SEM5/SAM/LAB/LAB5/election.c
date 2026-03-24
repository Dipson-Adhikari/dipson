#include <stdio.h>

int main() {
   
    double T[3][3] = {
        {0.70, 0.20, 0.10},  // From D
        {0.10, 0.80, 0.10},  // From R
        {0.30, 0.30, 0.40}   // From I
    };

   
    double P0[3] = {0.48, 0.51, 0.01};

    double P1[3] = {0, 0, 0};

    
    int N = 1;

    
    for(int step = 0; step < N; step++) {
        for(int i = 0; i < 3; i++) {
            P1[i] = 0;
            for(int j = 0; j < 3; j++) {
                P1[i] += P0[j] * T[j][i];
            }
        }

       
        for(int i = 0; i < 3; i++) {
            P0[i] = P1[i];
        }
    }

    
    printf("Next Election Distribution:\n");
    printf("Democratic  = %.3lf\n", P1[0]);
    printf("Republican  = %.3lf\n", P1[1]);
    printf("Independent = %.3lf\n", P1[2]);

    return 0;
}