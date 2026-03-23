#include <iostream>
#include <string>
using namespace std;

int modInverse(int a) {
    a = a % 26;
    for (int x = 1; x < 26; x++)
        if ((a * x) % 26 == 1)
            return x;
    return -1;
}

int main() {
    string pt;
    int key[3][3], invKey[3][3];
    
    cout << "Enter plaintext: ";
    cin >> pt;

    cout << "Enter 3x3 key matrix:\n";
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> key[i][j];

    int len = pt.length();

    // Padding
    while(len % 3 != 0){
        pt += 'x';
        len++;
    }

    string ct = "";

    // Encryption
    for(int i=0;i<len;i+=3){
        for(int j=0;j<3;j++){
            int sum = 0;
            for(int k=0;k<3;k++){
                sum += key[j][k] * (pt[i+k] - 'a');
            }
            ct += (sum % 26) + 'A';
        }
    }

    cout << "Ciphertext: " << ct << endl;

    // Determinant
    int det =
    key[0][0]*(key[1][1]*key[2][2]-key[1][2]*key[2][1]) -
    key[0][1]*(key[1][0]*key[2][2]-key[1][2]*key[2][0]) +
    key[0][2]*(key[1][0]*key[2][1]-key[1][1]*key[2][0]);

    det = ((det % 26) + 26) % 26;

    int detInv = modInverse(det);

    if(detInv == -1){
        cout << "Key not invertible\n";
        return 0;
    }

    // Adjoint matrix
    invKey[0][0] = (key[1][1]*key[2][2]-key[1][2]*key[2][1]);
    invKey[0][1] = -(key[0][1]*key[2][2]-key[0][2]*key[2][1]);
    invKey[0][2] = (key[0][1]*key[1][2]-key[0][2]*key[1][1]);

    invKey[1][0] = -(key[1][0]*key[2][2]-key[1][2]*key[2][0]);
    invKey[1][1] = (key[0][0]*key[2][2]-key[0][2]*key[2][0]);
    invKey[1][2] = -(key[0][0]*key[1][2]-key[0][2]*key[1][0]);

    invKey[2][0] = (key[1][0]*key[2][1]-key[1][1]*key[2][0]);
    invKey[2][1] = -(key[0][0]*key[2][1]-key[0][1]*key[2][0]);
    invKey[2][2] = (key[0][0]*key[1][1]-key[0][1]*key[1][0]);

    // Multiply adjoint with determinant inverse
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            invKey[i][j] = ((invKey[i][j]*detInv)%26+26)%26;

    // Decryption
    string decrypted = "";

    for(int i=0;i<len;i+=3){
        for(int j=0;j<3;j++){
            int sum = 0;
            for(int k=0;k<3;k++){
                sum += invKey[j][k]*(ct[i+k]-'A');
            }
            decrypted += (sum%26)+'a';
        }
    }

    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}