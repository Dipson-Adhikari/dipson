#include <stdio.h>

int main()
{
    int n, i, j, gcd, count = 0;

    printf("Enter number: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
       
        int a = i, b = n;

        while(b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        gcd = a;

        if(gcd == 1)
        {
            printf("%d\t",i);
            count++;
        }   
    }

    printf("\nEuler Totient value = %d\n", count);

    return 0;
}