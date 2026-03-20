#include<iostream>
#include <cstring>
using namespace std;
int main()
{
    char pt[20],ct[20];
    int key;
    cout<<"Enter Plain Text: ";
    cin.getline(pt,20);
    cout<<"Enter Key :";
    cin>>key;
    cout<<".....Encryption Process....."<<endl;
    cout<<"Plain Text: "<<pt<<endl;
    cout<<"Key: "<<key<<endl;
    for(int i=0;i<strlen(pt);i++)
    {
        if(pt[i]==' ')
        {
            ct[i]=' ';
            continue;
        }
        ct[i]=((pt[i]-97)+key)%26 +65;
       
    }
    ct[strlen(pt)]='\0';
    cout<<"Cipher Text: "<<ct<<endl;
    cout<<".....Decryption Process....."<<endl;
    cout<<"Cipher Text: "<<ct<<endl;
    cout<<"Key: "<<key<<endl;
    for(int i=0;i<strlen(ct);i++)
    {
        if(ct[i]==' ')
        {
            pt[i]=' ';
            continue;
        }
        pt[i]=(((26+ct[i]-65)-key)%26)+65;
    }
    cout<<"Plain Text: "<<pt<<endl;
    return 0;   
}
