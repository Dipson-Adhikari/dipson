#include <stdio.h>
#include <math.h>

int main() {
    int n, i;
    float data[100];
    int k = 10;                  // number of intervals
    int O[10] = {0};             // observed frequency
    float E, chi = 0;

    // Step 1: Input N
    printf("Enter number of random numbers: ");
    scanf("%d", &n);

    // Step 2: Input numbers
    printf("Enter numbers between 0 and 1:\n");
    for(i = 0; i < n; i++) {
        scanf("%f", &data[i]);

        // Determine interval (0-0.1, 0.1-0.2, ...)
        int index = data[i] * 10;
        if(index == 10) index = 9;   // handle 1.0 case

        O[index]++;
    }

    // Step 3: Calculate Expected frequency
    E = n / (float)k;

    printf("\nInterval\tOi\tEi\t(Oi-Ei)^2/Ei\n");

    // Step 4: Calculate Chi-Square
    for(i = 0; i < k; i++) {
        float diff = O[i] - E;
        float value = (diff * diff) / E;
        chi += value;

        printf("%d\t\t%d\t%.2f\t%.2f\n", i+1, O[i], E, value);
    }

    printf("\nChi-Square Calculated = %.2f\n", chi);

    // Step 5: Input Chi-table value
    float chi_table;
    printf("Enter Chi-Square table value: ");
    scanf("%f", &chi_table);

    // Step 6: Decision
    if(chi < chi_table)
        printf("Accept H0 → Uniform Distribution\n");
    else
        printf("Reject H0 → Not Uniform\n");

    return 0;
}