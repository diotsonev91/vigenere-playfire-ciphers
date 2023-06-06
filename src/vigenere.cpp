#include <iostream>
#include <string>
#include "util.h"

std::string vigenere_encrypt(const std::string& plaintext, const std::string& key) {
   
    std::string ciphertext;

    // Prepare the message
    std::string preparedMessage = prepareMessage(plaintext);


    int keyLength = key.length();

    for (size_t i = 0; i < preparedMessage.length(); ++i) {
        char currentChar = preparedMessage[i];
        char keyChar = key[i % keyLength];
        
        if (currentChar == ' ' || currentChar == '.') {
            ciphertext.push_back(currentChar);
            continue;
        }

        char encryptedChar = (currentChar + keyChar - 2 * 'A') % 26 + 'A'; // Assuming uppercase letters only
        ciphertext.push_back(encryptedChar);
    }

    return ciphertext;
}

std::string vigenere_decrypt(const std::string& ciphertext, const std::string& key) {
    std::string plaintext;
    int keyLength = key.length();

    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char currentChar = ciphertext[i];
        char keyChar = key[i % keyLength];

        if (currentChar == ' ' || currentChar == '.') {
            plaintext.push_back(currentChar);
            continue;
        }

        char decryptedChar = (currentChar - keyChar + 26) % 26 + 'A'; // Assuming uppercase letters only
        plaintext.push_back(decryptedChar);
    }

    return plaintext;
}