#include<stdio.h>
#include<string.h>

int main()
{
    char text[100], key[100], cipher[100], decrypted[100];
    int i,j,k;

    printf("Enter Plain Text: ");
    gets(text);

    printf("Enter Key: ");
    gets(key);

    char uniqueKey[100] = "";
    int index = 0;

    for(i = 0; key[i] != '\0'; i++)
    {
        if(strchr(uniqueKey, key[i]) == NULL)
        {
            uniqueKey[index++] = key[i];
        }
    }
    uniqueKey[index] = '\0';

    char matrix[5][5];
    int used[26] = {0};
    k = 0;

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(k < index)
            {
                matrix[i][j] = uniqueKey[k++];
                used[uniqueKey[k-1] - 'a'] = 1;
            }
            else
            {
                for(int ch = 'a'; ch <= 'z'; ch++)
                {
                    if(ch == 'j') continue;

                    if(!used[ch - 'a'])
                    {
                        matrix[i][j] = ch;
                        used[ch - 'a'] = 1;
                        break;
                    }
                }
            }
        }
    }

    printf("\nPlayfair Matrix:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
            printf("%c ",matrix[i][j]);
        printf("\n");
    }

    int idx = 0;

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] == ' ') continue;
        cipher[idx++] = text[i];
    }
    cipher[idx] = '\0';

    // Encryption
    for(i = 0; cipher[i] != '\0'; i += 2)
    {
        char a = cipher[i];
        char b = (cipher[i + 1] != '\0') ? cipher[i + 1] : 'x';

        int rowA,colA,rowB,colB;

        for(j=0;j<5;j++)
        {
            for(k=0;k<5;k++)
            {
                if(matrix[j][k]==a)
                {
                    rowA=j;
                    colA=k;
                }
                if(matrix[j][k]==b)
                {
                    rowB=j;
                    colB=k;
                }
            }
        }

        if(rowA==rowB)
        {
            cipher[i]=matrix[rowA][(colA+1)%5];
            cipher[i+1]=matrix[rowB][(colB+1)%5];
        }
        else if(colA==colB)
        {
            cipher[i]=matrix[(rowA+1)%5][colA];
            cipher[i+1]=matrix[(rowB+1)%5][colB];
        }
        else
        {
            cipher[i]=matrix[rowA][colB];
            cipher[i+1]=matrix[rowB][colA];
        }
    }

    printf("\nCipher Text: %s\n",cipher);

    // Decryption
    for(i = 0; cipher[i] != '\0'; i += 2)
    {
        char a = cipher[i];
        char b = cipher[i+1];

        int rowA,colA,rowB,colB;

        for(j=0;j<5;j++)
        {
            for(k=0;k<5;k++)
            {
                if(matrix[j][k]==a)
                {
                    rowA=j;
                    colA=k;
                }
                if(matrix[j][k]==b)
                {
                    rowB=j;
                    colB=k;
                }
            }
        }

        if(rowA==rowB)
        {
            decrypted[i]=matrix[rowA][(colA+4)%5];
            decrypted[i+1]=matrix[rowB][(colB+4)%5];
        }
        else if(colA==colB)
        {
            decrypted[i]=matrix[(rowA+4)%5][colA];
            decrypted[i+1]=matrix[(rowB+4)%5][colB];
        }
        else
        {
            decrypted[i]=matrix[rowA][colB];
            decrypted[i+1]=matrix[rowB][colA];
        }
    }

    decrypted[idx]='\0';

    printf("Decrypted Text: %s\n",decrypted);

    return 0;
}