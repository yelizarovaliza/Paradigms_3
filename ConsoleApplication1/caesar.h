#ifndef CAESAR_H
#define CAESAR_H

#include <cstring>

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

	DLL_EXPORT char* encrypt(char* rawText, int key);
	DLL_EXPORT char* decrypt(char* encryptedText, int key);

#ifdef __cplusplus
}
#endif

#endif // CAESAR_H
