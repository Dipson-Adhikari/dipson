//to find gcd of two numbers using iterative method

#include <stdio.h>
int gcd_iterative(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    int a, b, gcd;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    gcd = gcd_iterative(a, b);
    printf("GCD of %d and %d is %d", a, b, gcd);
    return 0;
}