#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char pt[100], key[100], ct[100], dt[100];
    int i, len;

    printf("Enter Plain Text: ");
    gets(pt);

    len = strlen(pt);

    srand(time(0));

    // Generate random key
    for(i = 0; i < len; i++)
    {
        key[i] = (rand() % 26) + 'a';
    }
    key[len] = '\0';

    printf("Random Key: %s\n", key);

    // Encryption
    for(i = 0; i < len; i++)
    {
        ct[i] = ((pt[i] - 'a') + (key[i] - 'a')) % 26 + 'a';
    }
    ct[len] = '\0';

    printf("Cipher Text: %s\n", ct);

    // Decryption
    for(i = 0; i < len; i++)
    {
        dt[i] = ((ct[i] - 'a') - (key[i] - 'a') + 26) % 26 + 'a';
    }
    dt[len] = '\0';

    printf("Decrypted Text: %s\n", dt);

    return 0;
}