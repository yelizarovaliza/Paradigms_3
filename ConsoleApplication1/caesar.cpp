#include <iostream>
#include <cstring>

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

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

extern "C" {
    DLL_EXPORT char* encrypt(char* rawText, int key) {
        return CaesarCipher::encrypt(rawText, key);
    }

    DLL_EXPORT char* decrypt(char* encryptedText, int key) {
        return CaesarCipher::decrypt(encryptedText, key);
    }
}
