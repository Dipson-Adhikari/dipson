//WAP TO TEST WHETHER GIVEN NUMBER IS PRIME OR NOT USING MILLER'S RABIN ALGORITHM.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, k = 0, i, j;
    int a, b;

    printf("Enter number: ");
    scanf("%d", &n);

    
    m = n - 1;
    while(m % 2 == 0)
    {
        m = m / 2;
        k++;
    }

   //choose a random a
    a = 2;   

  
    b = 1;
    for(i = 0; i < m; i++)
    {
        b = (b * a) % n;
    }

    
    if(b == 1)
    {
        printf("Probably Prime\n");
        return 0;
    }

  
    for(j = 0; j < k; j++)
    {
        if(b == n - 1)
        {
            printf(" Prime\n");
            return 0;
        }
        else
        {
            b = (b * b) % n;
        }
    }

   
    printf("Composite\n");

    return 0;
}