#include <stdio.h>

// Modular exponentiation
int modExp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

// Modular inverse
int modInverse(int a, int p) {
    int i;
    for (i = 1; i < p; i++) {
        if ((a * i) % p == 1)
            return i;
    }
    return -1;
}

int main() {
    int p, g, x, y, k, m;
    int c1, c2, decrypted;

    // Input
    printf("Enter prime number p: ");
    scanf("%d", &p);

    printf("Enter primitive root g: ");
    scanf("%d", &g);

    printf("Enter private key x: ");
    scanf("%d", &x);

    printf("Enter message (integer): ");
    scanf("%d", &m);

    // Key Generation
    y = modExp(g, x, p);
    printf("Public Key (p, g, y): (%d, %d, %d)\n", p, g, y);

    // Encryption
    printf("Enter random k: ");
    scanf("%d", &k);

    c1 = modExp(g, k, p);
    c2 = (m * modExp(y, k, p)) % p;

    printf("Encrypted (c1, c2) = (%d, %d)\n", c1, c2);

    // Decryption
    int s = modExp(c1, x, p);
    int s_inv = modInverse(s, p);

    decrypted = (c2 * s_inv) % p;

    printf("Decrypted message = %d\n", decrypted);

    return 0;
}