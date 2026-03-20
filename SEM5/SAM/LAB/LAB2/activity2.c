// ACTIVITY 2: Finding cycle length modify the above program (activity1) and find the cycle length once you identify
// there is present of same random number as given in seed , you have to terminate your program.
// e.g in activity 1 if you try to generate 20 random numbers the numbers repeat after 15 unique numbers (2,21,6,26,20,28,7,4,8,13,27,29,16,23,21,2..)
// In this case your program should stop genrating repeated random numbers.

#include <stdio.h>
#include <math.h>

int main()
{
    int numbers, Ro, a, c, m, Ri, i = 0,cycle_length=0;
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
    printf("Generated Random Numbers:\n");
    Ri = Ro;
    while (i < numbers)
    {
        Ri = (a * Ri + c) % m;
        if (Ri == Ro)
        {   
            cycle_length = i;
            printf("\nCycle detected after %d iterations. Terminating program.\n", cycle_length);
            break;
        }
        printf("%d ", Ri);
        i++;
    }
    return 0;
}