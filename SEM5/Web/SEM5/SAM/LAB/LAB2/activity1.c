// ACTIVITY 1: use linear congruential method (LCM) to genrate random numbers.
// Your program should ask for user input like how many digits how many numbers initial value (Ro),constant value: a and c
// then calculate the Random Number using Ri+1=(a*Ri+c)mod m where m should ne determine based on the number of digits
// use:a =9,c=3,m=31,Ro=2

#include <stdio.h>
#include <math.h>

int main()
{
    int numbers, Ro, a, c, m, Ri, i = 0;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &numbers);
    printf("Enter the initial value (Ro): ");
    scanf("%d", &Ro);
    printf("Enter the multipler (a): ");
    scanf("%d", &a);
    printf("Enter the increment value (c): ");
    scanf("%d", &c);
    printf("Enter the modulus value (m): ");
    scanf("%d", &m);
    printf("Generated Random Numbers:2 ");
    Ri = Ro;

    while (i < numbers)
    {
        Ri = (a * Ri + c) % m;
        printf("%d ", Ri);
        i++;
    }
    return 0;
}