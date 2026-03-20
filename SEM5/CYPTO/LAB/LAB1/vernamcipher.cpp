#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char pt[20], ct[20], key[20];

    cout << "Enter Plain Text: ";
    cin.getline(pt, 20);

    cout << "Enter Key: ";
    cin.getline(key, 20);

    int pt_len = strlen(pt);
    int key_len = strlen(key);

    int z = 0;
    for (int i = key_len; i < pt_len; i++)
    {
        if (pt[i] == ' ')
        {
            key[i] = ' ';
        }
        else
        {
            key[i] = key[z % key_len];
            z++;
        }
    }
    key[pt_len] = '\0';

    cout << "\n.....Encryption Process.....\n";
    cout << "Plain Text: " << pt << endl;
    cout << "Key: " << key << endl;

    // Encryption
    for (int i = 0; pt[i] != '\0'; i++)
    {
        if (pt[i] == ' ')
        {
            ct[i] = ' ';
        }
        else
        {
            ct[i] = (((pt[i] - 97) + (key[i] - 97)) % 26) + 65;
        }
    }
    ct[pt_len] = '\0';

    cout << "Cipher Text: " << ct << endl;

    cout << "\n.....Decryption Process.....\n";
    cout << "Cipher Text: " << ct << endl;
    cout << "Key: " << key << endl;

    // Decryption
    for (int i = 0; ct[i] != '\0'; i++)
    {
        if (ct[i] == ' ')
        {
            pt[i] = ' ';
        }
        else
        {
            pt[i] = (((ct[i] - 65) - (key[i] - 97) + 26) % 26) + 97;
        }
    }
    pt[pt_len] = '\0';

    cout << "Plain Text: " << pt << endl;

    return 0;
}
