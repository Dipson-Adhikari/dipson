#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j;
    float R[100], temp;
    float Dplus[100], Dminus[100];
    float DplusMax, DminusMax, D, Dalpha;

    // Step 1: Input N
    printf("Enter number of random numbers (N): ");
    scanf("%d", &n);

    // Step 2: Input numbers
    printf("Enter %d random numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%f", &R[i]);
    }

    // Step 3: Sort using Bubble Sort
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(R[j] > R[j + 1]) {
                temp = R[j];
                R[j] = R[j + 1];
                R[j + 1] = temp;
            }
        }
    }

    // Display sorted data
    printf("\nSorted Data:\n");
    for(i = 0; i < n; i++) {
        printf("%f ", R[i]);
    }

    // Step 4: Calculate D+ and D-
    for(i = 0; i < n; i++) {
        Dplus[i] = ((i + 1) / (float)n) - R[i];
        Dminus[i] = R[i] - (i / (float)n);
    }

    // Display D+ and D-
    printf("\n\nD+ values:\n");
    for(i = 0; i < n; i++) {
        printf("%f ", Dplus[i]);
    }

    printf("\n\nD- values:\n");
    for(i = 0; i < n; i++) {
        printf("%f ", Dminus[i]);
    }

    // Step 5: Find D+max and D-max (max approach)
    DplusMax = Dplus[0];
    DminusMax = Dminus[0];

    for(i = 1; i < n; i++) {
        if(DplusMax < Dplus[i]) {
            DplusMax = Dplus[i];
        }
        if(DminusMax < Dminus[i]) {
            DminusMax = Dminus[i];
        }
    }

    printf("\n\nD+ max = %f", DplusMax);
    printf("\nD- max = %f", DminusMax);

    // Step 6: Calculate D
    if(DplusMax > DminusMax)
        D = DplusMax;
    else
        D = DminusMax;

    printf("\nD  = %f\n", D);

    // Step 7: Input Dalpha
    printf("\nEnter tabulated value Dalpha: ");
    scanf("%f", &Dalpha);

    // Step 8: Decision
    if(D < Dalpha) {
        printf("\nNull Hypothesis cannot be rejected\n");
        printf("Numbers are uniformly distributed\n");
    } else {
        printf("\nNull Hypothesis rejected\n");
        printf("Numbers are NOT uniformly distributed\n");
    }

    return 0;
}