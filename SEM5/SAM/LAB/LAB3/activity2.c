#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    int k = 10;
    int O[10] = {0};
    float E, chi = 0;

    // LCG parameters
    int a = 5, c = 3, m = 16, X = 7;

    printf("Enter how many random numbers (>=40): ");
    scanf("%d", &n);

    if(n < 40) {
        printf("Please enter at least 40 numbers!\n");
        return   0;
    }

    float R[100];

    // Generate numbers using LCG
    for(i = 0; i < n; i++) {
        X = (a * X + c) % m;
        R[i] = X / (float)m;

        int index = R[i] * 10;
        if(index == 10) index = 9;

        O[index]++;
    }

    // Expected frequency
    E = n / (float)k;

    printf("\nGenerated Numbers:\n");
    for(i = 0; i < n; i++) {
        printf("%.3f ", R[i]);
    }

    printf("\n\nInterval\tOi\tEi\t(Oi-Ei)^2/Ei\n");

    // Chi-square calculation
    for(i = 0; i < k; i++) {
        float diff = O[i] - E;
        float value = (diff * diff) / E;
        chi += value;

        printf("%d\t\t%d\t%.2f\t%.2f\n", i+1, O[i], E, value);
    }

    printf("\nChi-Square = %.2f\n", chi);

    float chi_table;
    printf("Enter Chi-table value: ");
    scanf("%f", &chi_table);

    if(chi < chi_table)
        printf("Accept H0 → Uniform\n");
    else
        printf("Reject H0 → Not Uniform\n");

    return 0;
}