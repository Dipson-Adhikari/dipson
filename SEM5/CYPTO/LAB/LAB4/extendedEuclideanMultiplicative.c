#include <stdio.h>

int main() {
    int a, n;

    printf("Enter the number and the modulus: ");
    scanf("%d %d", &a, &n);

    int r1 = n, r2 = a;
    int t1 = 0, t2 = 1;
    int q, r, t;
    

    //table 
    printf("r1\tr2\tt1\tt2\tq\tr\tt\n");

    while (r2 > 0) {
        q = r1 / r2;

        r = r1 - q * r2;
        t = t1 - q * t2;

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", r1, r2, t1, t2, q, r, t);

        r1 = r2;
        r2 = r;
        t1 = t2;
        t2 = t;
    }

    

    if (r1 == 1) { 
        if (t1 < 0)
            t1 += n; 

        printf("Multiplicative inverse of %d in Z%d is %d\n", a, n, t1);
    } else {
        printf("Multiplicative inverse does not exist for %d in Z%d\n", a, n);
    }

    return 0;
}