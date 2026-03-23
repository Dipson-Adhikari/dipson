#include <stdio.h>

int main()
{
    int p, g;
    int XA, XB;
    int YA = 1, YB = 1;
    int KA = 1, KB = 1;
    int i;

    printf("Enter prime number p: ");
    scanf("%d", &p);

    printf("Enter primitive root g: ");
    scanf("%d", &g);

    //  User A private key
    printf("Enter private key of A (XA): ");
    scanf("%d", &XA);

    // compute YA = g^XA mod p
    for(i = 0; i < XA; i++)
    {
        YA = (YA * g) % p;
    }

    //  User B private key
    printf("Enter private key of B (XB): ");
    scanf("%d", &XB);

    // YB = g^XB mod p
    for(i = 0; i < XB; i++)
    {
        YB = (YB * g) % p;
    }

    printf("Public key of A (YA): %d\n", YA);
    printf("Public key of B (YB): %d\n", YB);

    //  KA = (YB^XA) mod p
    for(i = 0; i < XA; i++)
    {
        KA = (KA * YB) % p;
    }

    //  KB = (YA^XB) mod p
    for(i = 0; i < XB; i++)
    {
        KB = (KB * YA) % p;
    }

    printf("Secret key computed by A: %d\n", KA);
    printf("Secret key computed by B: %d\n", KB);

    return 0;
}