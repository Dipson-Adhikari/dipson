//program to implement additive inverse of a number in Zn
#include<stdio.h>
int main()
{
    int a,n;
    printf("Enter the number and the modulus: ");
    scanf("%d%d",&a,&n);
   
    for(int i = 0; i < n; i++) {
         int inverse = (n - i) % n;
            printf("The additive inverse of %d in Z%d is: %d\n", i, n, inverse);
        
    }

    return 0;
}