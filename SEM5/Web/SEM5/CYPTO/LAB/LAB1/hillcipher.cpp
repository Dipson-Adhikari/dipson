#include <iostream>
#include <string>
using namespace std;

int main() {
    int row = 2, cols = 2, i, j, k, tempPt[2], det, detInverse, gcd, sum;
    string pt, ct;

    cout << "Enter plain text: ";
    getline(cin, pt);

    int key[2][2], invKey[2][2];

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            cout << "Enter the key for " << i + 1 << "X" << j + 1 << "\t";
            cin >> key[i][j];
        }
    }

    det = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    det = det % 26;
    if (det < 0) det += 26;

    gcd = det;
    int b = 26;

    while (b != 0) {
        int temp = gcd % b;
        gcd = b;
        b = temp;
    }

    if (gcd == 1) {
        cout << "Key is valid\n";
        cout << "\nEncryption Process\n";

        int len = pt.length();

        if (len % 2 != 0) {
            pt += 'x';
            len++;
        }

        ct.resize(len);

        for (i = 0; i < len; i += 2) {
            tempPt[0] = pt[i] - 'a';
            tempPt[1] = pt[i + 1] - 'a';

            for (j = 0; j < 2; j++) {
                int val = 0;
                for (k = 0; k < 2; k++) {
                    val += key[j][k] * tempPt[k];
                }
                ct[i + j] = (val % 26) + 'A';
            }
        }

        cout << "Cipher text: " << ct << endl;

        cout << "\nDecryption Process\n";

        detInverse = 0;
        for (i = 1; i < 26; i++) {
            if ((det * i) % 26 == 1) {
                detInverse = i;
                break;
            }
        }

        if (detInverse == 0) {
            cout << "Error: Cannot find modular inverse\n";
            return 1;
        }

        invKey[0][0] = key[1][1];
        invKey[0][1] = -key[0][1];
        invKey[1][0] = -key[1][0];
        invKey[1][1] = key[0][0];

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                invKey[i][j] = invKey[i][j] * detInverse;
                invKey[i][j] = ((invKey[i][j] % 26) + 26) % 26;
            }
        }

        for (i = 0; i < len; i += 2) {
            tempPt[0] = ct[i] - 'A';
            tempPt[1] = ct[i + 1] - 'A';

            for (j = 0; j < 2; j++) {
                sum = 0;
                for (k = 0; k < 2; k++) {
                    sum += invKey[j][k] * tempPt[k];
                }
                pt[i + j] = ((sum % 26) + 26) % 26 + 'a';
            }
        }

        cout << "Plain text: " << pt << endl;

    } else {
        cout << "Key is not valid (GCD != 1)\n";
        return 1;
    }

    return 0;
}