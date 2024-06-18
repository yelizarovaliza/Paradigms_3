#pragma once

extern "C" {

	DLL_EXPORT char* encrypt(char* rawText, int key);
	DLL_EXPORT char* decrypt(char* encryptedText, int key);

}
