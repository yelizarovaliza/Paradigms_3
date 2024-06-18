#include <windows.h>
#include <iostream>
#include "caesar.h"

using namespace std;

typedef char* (*encrypt_ptr)(char*, int);
typedef char* (*decrypt_ptr)(char*, int);

int main() {
    HINSTANCE hDll = LoadLibrary(TEXT("caesar.dll"));
    if (!hDll) {
        DWORD error = GetLastError();
        cerr << "Could not load the DLL! Error code: " << error << endl;
        return 1;
    }

    encrypt_ptr encrypt = (encrypt_ptr)GetProcAddress(hDll, "encrypt");
    decrypt_ptr decrypt = (decrypt_ptr)GetProcAddress(hDll, "decrypt");

    if (!encrypt || !decrypt) {
        cerr << "Could not locate the functions!" << endl;
        FreeLibrary(hDll);
        return 1;
    }

    char rawText[] = "Roses are red, violets are blue";
    int key = 1;

    char* encrypted = encrypt(rawText, key);
    char* decrypted = decrypt(encrypted, key);

    cout << "Original Text: " << rawText << endl;
    cout << "Encrypted Text: " << encrypted << endl;
    cout << "Decrypted Text: " << decrypted << endl;

    delete[] encrypted;
    delete[] decrypted;

    FreeLibrary(hDll);
    return 0;
}