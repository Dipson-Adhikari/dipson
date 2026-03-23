#include <stdio.h>

// S1 Box (first S-Box of DES)
int S1[4][16] = {
    {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
    {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
    {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
    {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
};

// Convert 6-bit block to decimal
int binToDec(int bin[], int len) {
    int val = 0;
    for(int i=0; i<len; i++)
        val = val*2 + bin[i];
    return val;
}

// Convert decimal to 4-bit binary
void decToBin(int num, int bin[]) {
    for(int i=3; i>=0; i--) {
        bin[i] = num % 2;
        num /= 2;
    }
}

int main() {
    int input6[6];   // 6-bit input
    int output4[4];  // 4-bit output

    printf("S1 Box:\n");
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<16; j++)
            printf("%d \t", S1[i][j]);
        printf("\n");
    }   
        
    printf("Enter 6-bit input for S1 (0/1): ");
    for(int i=0; i<6; i++)
        scanf("%d", &input6[i]);

    // Row = first and last bit
    int row = input6[0]*2 + input6[5];
    printf("Row: %d\n", row);

    // Column = middle 4 bits
    int col = input6[1]*8 + input6[2]*4 + input6[3]*2 + input6[4];

    printf("Column: %d\n", col);

    int val = S1[row][col];
    decToBin(val, output4);     

    printf("Decimal value from S1: %d\n", val);

    printf("Output from S1: ");
    for(int i=0; i<4; i++)
        printf("%d", output4[i]);
    printf("\n");

    return 0;
}