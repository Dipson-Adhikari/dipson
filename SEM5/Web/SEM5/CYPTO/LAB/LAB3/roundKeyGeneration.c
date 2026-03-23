//program to generate 16 round keys in DES algorithm
#include <stdio.h>

// PC-1 table 
int PC1[56] = {
57,49,41,33,25,17,9,
1,58,50,42,34,26,18,
10,2,59,51,43,35,27,
19,11,3,60,52,44,36,
63,55,47,39,31,23,15,
7,62,54,46,38,30,22,
14,6,61,53,45,37,29,
21,13,5,28,20,12,4
};

// PC-2 table 
int PC2[48] = {
14,17,11,24,1,5,
3,28,15,6,21,10,
23,19,12,4,26,8,
16,7,27,20,13,2,
41,52,31,37,47,55,
30,40,51,45,33,48,
44,49,39,56,34,53,
46,42,50,36,29,32
};

int shift[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

// Function to left shift
void leftShift(int arr[], int shifts)
{
    while(shifts--)
    {
        int temp = arr[0];
        for(int i = 0; i < 27; i++)
            arr[i] = arr[i+1];
        arr[27] = temp;
    }
}

int main()
{
    int originalKey[64] = {
    1,0,1,0,0,1,1,1,   
    0,1,1,0,1,0,0,0,   
    1,1,0,1,0,1,1,0,   
    0,0,1,1,1,0,1,1,   
    1,0,0,1,1,1,0,0,   
    0,1,0,0,1,0,1,1,   
    1,1,1,0,0,1,0,1,  
    0,0,1,1,0,1,1,0    
};
    printf("Original Key: ");
    for(int i=0; i<64; i++)
        printf("%d", originalKey[i]);
    printf("\n");
    
    int permutedKey[56];
    int left[28], right[28];
    int roundKey[16][48];

    // PC-1 permutation
    for(int i=0; i<56; i++)
        permutedKey[i] = originalKey[PC1[i]-1];

    // Split into left and right
    for(int i=0; i<28; i++)
    {
        left[i] = permutedKey[i];
        right[i] = permutedKey[i+28];
    }
    printf("After PC-1 Permutation:\nLeft:  ");
    for(int i=0; i<28; i++)
        printf("%d", left[i]);      
    printf("\nRight: ");
    for(int i=0; i<28; i++)
        printf("%d", right[i]);
    printf("\n");
    
    // Generate 16 round keys
    for(int i=0; i<16; i++)
    {
        // Shift
        leftShift(left, shift[i]);
        leftShift(right, shift[i]);

        int combined[56];

        // Combine
        for(int j=0; j<28; j++)
        {
            combined[j] = left[j];
            combined[j+28] = right[j];
        }

        // PC-2 permutation
        for(int j=0; j<48; j++)
            roundKey[i][j] = combined[PC2[j]-1];
    }

    // Print round keys
    printf("\n16 Round Keys:\n");
    for(int i=0; i<16; i++)
    {
        printf("Round %2d: ", i+1);
        for(int j=0; j<48; j++)
            printf("%d", roundKey[i][j]);
        printf("\n");
    }

    return 0;
}