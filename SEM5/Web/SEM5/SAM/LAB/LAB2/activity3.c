// <!-- ACTIVITY 3:Apply all LCM (Additive,Mixed or Multiplicative) based on the input value of a and c (detemine the type 
// and generate the random numbers based on that).in this case you can provide a choice to user whihc method they want 
// to choose.Based on the choice you should apply the respective formulas. -->

#include <stdio.h>
#include <math.h>

int main()
{
    int numbers, Ro, a, c, m, Ri, i = 0, choice;
    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &numbers);
    printf("Enter the initial value (Ro): ");
    scanf("%d", &Ro);
    printf("Enter the modulus value (m): ");
    scanf("%d", &m);
    printf("Choose the type of LCM:\n1. Additive\n2. Mixed\n3. Multiplicative\n");
    scanf("%d", &choice);

    Ri = Ro;
        switch (choice)
        {
        case 1:
            printf("Enter the increment value (c): ");
            scanf("%d", &c);
            while(i < numbers)
            {
                Ri = (Ri + c) % m;
                printf("%d ", Ri);
                i++;
            }
            break;

        case 2:
            printf("Enter the multipler (a): ");
            scanf("%d", &a);
            printf("Enter the increment value (c): ");
            scanf("%d", &c);
            while(i < numbers)
            {
                Ri = (a * Ri + c) % m;
                printf("%d ", Ri);
                i++;
            }
            break;
        case 3:
            printf("Enter the multipler (a): ");
            scanf("%d", &a);
            while(i < numbers)
            {
                Ri = (a * Ri) % m;
                printf("%d ", Ri);
                i++;
            }
            break;
            
        default:
            printf("Invalid choice. Please select 1, 2, or 3.\n");
            break;    
        }
    return 0;
}