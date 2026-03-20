#include <stdio.h>

// modular exponentiation
int modExp(int base, int exp, int mod)
{
    int result = 1;
    base = base % mod;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// gcd function
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// modular inverse
int modInverse(int e, int phi)
{
    int d;
    for (d = 1; d < phi; d++)
    {
        if ((d * e) % phi == 1)
            return d;
    }
    return -1;
}

int main()
{
    int p, q, n, phi;
    int e, d;
    int m, c, decrypted;

    // Step 1: input p and q
    printf("Enter two prime numbers p and q: ");
    scanf("%d%d", &p, &q);

    // Step 2: compute n and phi
    n = p * q;
    phi = (p - 1) * (q - 1);

    // Step 3: find e (coprime with phi)
    for (e = 2; e < phi; e++)
    {
        if (gcd(e, phi) == 1)
            break;
    }

    // Step 4: find d
    d = modInverse(e, phi);

    // Step 5: display keys
    printf("Public Key (e, n): (%d, %d)\n", e, n);
    printf("Private Key (d, n): (%d, %d)\n", d, n);

    // Step 6: encryption
    printf("\nEnter message: ");
    scanf("%d", &m);

    c = modExp(m, e, n);
    printf("Encrypted message: %d\n", c);

    // Step 7: decryption
    decrypted = modExp(c, d, n);
    printf("Decrypted message: %d\n", decrypted);

    return 0;
}