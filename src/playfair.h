#ifndef PLAYFAIR_CIPHER_H
#define PLAYFAIR_CIPHER_H

#include <string>

std::string encryptMessage(const std::string& message, const std::string& key);
std::string decryptMessage(const std::string& ciphertext, const std::string& key);

#endif // PLAYFAIR_CIPHER_H
