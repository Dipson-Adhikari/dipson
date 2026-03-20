//to find the nth term of the Fibonacci sequence using iterative method

#include <stdio.h>
int fibonacci_iterative(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;

    int a = 0, b = 1, fib;
    for (int i = 2; i <= n; i++)
    {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}
int main()
{
    int n, fib;
    printf("Enter the term number: ");
    scanf("%d", &n);
    fib = fibonacci_iterative(n);
    printf("Fibonacci sequence:\n", n);
    for(int i=0;i<=n;i++)
    {
        printf("%d\t ",fibonacci_iterative(i));
    }
    printf("\nThe %dth term of the Fibonacci sequence is %d", n, fib);
    return 0;
}