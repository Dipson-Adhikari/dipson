//program to check if two numbers are relatively prime using  Euclidean Algorithm
#include <stdio.h>

int main() {
    int a, n;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &n);

    int r1 = a, r2 = n;
    int r;

    while (r2 != 0) {
        r = r1 % r2;  
        r1 = r2;
        r2 = r;
    }

    if (r1 == 1) {
        printf("%d and %d are relatively prime\n", a, n);
    } else {
        printf("%d and %d are not relatively prime\n", a, n);
    }

    return 0;
}