#include <windows.h>
#include <iostream>

using namespace std;

typedef char* (*encrypt_ptr)(const char*, int);
typedef char* (*decrypt_ptr)(const char*, int);

int main() {
    HINSTANCE hDll = LoadLibrary(TEXT("caesar.dll"));
    if (!hDll) {
        cerr << "Could not load the DLL!" << endl;
        return 1;
    }

    EncryptFunc encrypt = (encrypt_ptr)GetProcAddress(hDll, "encrypt");
    DecryptFunc decrypt = (decrypt_ptr)GetProcAddress(hDll, "decrypt");

    if (!encrypt || !decrypt) {
        cerr << "Could not locate the functions!" << endl;
        FreeLibrary(hDll);
        return 1;
    }

    const char* rawText = "Roses are red, violets are blue";
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