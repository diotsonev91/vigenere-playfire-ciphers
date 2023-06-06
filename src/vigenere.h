#ifndef VIGENERE_H
#define VIGENERE_H
#include <string>
std::string vigenere_encrypt(const std::string& plaintext, const std::string& key);
std::string vigenere_decrypt(const std::string& ciphertext, const std::string& key);

#endif