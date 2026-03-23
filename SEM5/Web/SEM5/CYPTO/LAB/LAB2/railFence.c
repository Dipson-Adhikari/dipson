#include<stdio.h>
#include<string.h>

int main()
{
    char text[100], cipher[100], decrypted[100];
    int key,i,j,len;

    printf("Enter Plain Text: ");
    gets(text);

    printf("Enter size of rail: ");
    scanf("%d",&key);

    len=strlen(text);
    char rail[key][len];

  
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            rail[i][j]='\n';

    int row=0,dir=1;

    for(i=0;i<len;i++)
    {
        rail[row][i]=text[i];
        row+=dir;

        if(row==0 || row==key-1)
            dir=-dir;
    }

    printf("\nCipher Text: ");

    int index=0;
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            if(rail[i][j]!='\n')
            {
                printf("%c",rail[i][j]);
                cipher[index++]=rail[i][j];
            }

    cipher[index]='\0';

   //decrpyption

    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            rail[i][j]='\n';

    row=0;
    dir=1;

    for(i=0;i<len;i++)
    {
        rail[row][i]='*';
        row+=dir;

        if(row==0 || row==key-1)
            dir=-dir;
    }

    index=0;
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            if(rail[i][j]=='*')
                rail[i][j]=cipher[index++];

    row=0;
    dir=1;

    printf("\nDecrypted Text: ");

    for(i=0;i<len;i++)
    {
        printf("%c",rail[row][i]);
        row+=dir;

        if(row==0 || row==key-1)
            dir=-dir;
    }

    return 0;
}