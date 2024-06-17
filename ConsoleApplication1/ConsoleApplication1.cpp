#include <iostream>
#include <cstring>

using namespace std;

class CaesarCipher {
public:
    static char* encrypt(char* rawText, int key) {
        int len = strlen(rawText);
        char* encryptedText = new char[len + 1];

        for (int i = 0; i < len; ++i) {
            char c = rawText[i];
            if (isalpha(c)) {
                char base = isupper(c) ? 'A' : 'a';
                encryptedText[i] = (c - base + key) % 26 + base;
            }
            else {
                encryptedText[i] = c;
            }
        }
        encryptedText[len] = '\0';
        return encryptedText;
    }

    static char* decrypt(char* encryptedText, int key) {
        return encrypt(encryptedText, 26 - key);
    }
};

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
