#include <iostream>
#include <cstring>
#include "playfair.h"
#include "vigenere.h"

int main() {
    std::string key;

    int cipherType, operation;
    std::cout << "Select the cipher type:\n";
    std::cout << "1. Playfair\n";
    std::cout << "2. Vigenere\n";
    std::cin >> cipherType;

    std::cout << "Enter the key(ONLY ONE WORD KEY IS ALLOWED): ";
    std::cin.ignore(); // Ignore newline character
    std::getline(std::cin, key);

    // Convert key to uppercase and check for key spacese
    for (char& c : key) {
        if (std::islower(c)) {
            c = std::toupper(c);
        }
        if (std::isspace(c)) {
            std::cout << "ONLY ONE WORD KEY IS ALLOWED. PROGRAM CRASH NOW. SORRY";
            exit(-1);
        }
    }

    std::cout << "Select the operation:\n";
    std::cout << "1. Encryption\n";
    std::cout << "2. Decryption\n";
    std::cin >> operation;

    if (cipherType == 1) { // Playfair cipher
        if (operation == 1) { // Encryption
            std::string plaintext;
            std::cout << "Enter the plaintext: ";
            std::cin.ignore(); // Ignore newline character
            std::getline(std::cin, plaintext);

            std::string encryptedText = encryptMessage(plaintext, key);
            std::cout << "Playfair Encrypted Text: " << encryptedText << std::endl;
        } else if (operation == 2) { // Decryption
            std::string ciphertext;
            std::cout << "Enter the ciphertext: ";
            std::cin.ignore(); // Ignore newline character
            std::getline(std::cin, ciphertext);

            std::string decryptedText = decryptMessage(ciphertext, key);
            std::cout << "Playfair Decrypted Text: " << decryptedText << std::endl;
        } else {
            std::cout << "Invalid operation selected for Playfair cipher.\n";
        }
    } else if (cipherType == 2) { // Vigenere cipher
        if (operation == 1) { // Encryption
            std::string plaintext;
            std::cout << "Enter the plaintext: ";
            std::cin.ignore(); // Ignore newline character
            std::getline(std::cin, plaintext);

            std::string encryptedText = vigenere_encrypt(plaintext, key);
            std::cout << "Vigenere Encrypted Text: " << encryptedText << std::endl;
        } else if (operation == 2) { // Decryption
            std::string ciphertext;
            std::cout << "Enter the ciphertext: ";
            std::cin.ignore(); // Ignore newline character
            std::getline(std::cin, ciphertext);

            std::string decryptedText = vigenere_decrypt(ciphertext, key);
            std::cout << "Vigenere Decrypted Text: " << decryptedText << std::endl;
        } else {
            std::cout << "Invalid operation selected for Vigenere cipher.\n";
        }
    } else {
        std::cout << "Invalid cipher type selected.\n";
    }

    return 0;
}
