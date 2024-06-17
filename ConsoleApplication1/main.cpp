#include <iostream>
#include <cstring>

using namespace std;



int main() {
    char rawText[] = "Roses are red, violets are blue";
    int key = 1;

    char* encrypted = CaesarCipher::encrypt(rawText, key);
    char* decrypted = CaesarCipher::decrypt(encrypted, key);

    cout << "Original Text: " << rawText << endl;
    std::cout << "Encrypted Text: " << encrypted << endl;
    cout << "Decrypted Text: " << decrypted << endl;

    delete[] encrypted;
    delete[] decrypted;

    return 0;
}
