#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "util.h"

// Function to remove duplicate characters from the key
std::string removeDuplicates(const std::string& key) {
    std::string uniqueKey;
    std::vector<bool> visited(26, false);
    for (char c : key) {
        if (!visited[c - 'A']) {
            uniqueKey.push_back(c);
            visited[c - 'A'] = true;
        }
    }
    return uniqueKey;
}

// Function to generate the key table
void generateKeyTable(const std::string& key, std::vector<std::vector<char>>& keyTable) {
    std::string uniqueKey = removeDuplicates(key);

    // Fill the key table with the unique key
    int row = 0, col = 0;
    for (char c : uniqueKey) {
        keyTable[row][col] = c;
        col++;
        if (col == 5) {
            row++;
            col = 0;
        }
    }

    // Fill the remaining cells with the remaining alphabets
    char ch = 'A';
    while (row < 5) {
        if (col == 5) {
            row++;
            col = 0;
        }
        if (row == 5)
            break;
        if (std::find(uniqueKey.begin(), uniqueKey.end(), ch) == uniqueKey.end()) {
            keyTable[row][col] = ch;
            col++;
        }
        ch++;
    }
}

// Function to find the position of a character in the key table
std::pair<int, int> findCharPosition(const std::vector<std::vector<char>>& keyTable, char c) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyTable[i][j] == c) {
                return std::make_pair(i, j);
            }
        }
    }
    return std::make_pair(-1, -1);
}

// Function to encrypt a pair of characters using the key table
std::string encryptPair(const std::vector<std::vector<char>>& keyTable, char c1, char c2) {
    std::pair<int, int> pos1 = findCharPosition(keyTable, c1);
    std::pair<int, int> pos2 = findCharPosition(keyTable, c2);

    std::string encryptedPair;
    if (pos1.first == pos2.first) {
        encryptedPair.push_back(keyTable[pos1.first][(pos1.second + 1) % 5]);
        encryptedPair.push_back(keyTable[pos2.first][(pos2.second + 1) % 5]);
    } else if (pos1.second == pos2.second) {
        encryptedPair.push_back(keyTable[(pos1.first + 1) % 5][pos1.second]);
        encryptedPair.push_back(keyTable[(pos2.first + 1) % 5][pos2.second]);
    } else {
        encryptedPair.push_back(keyTable[pos1.first][pos2.second]);
        encryptedPair.push_back(keyTable[pos2.first][pos1.second]);
    }
    return encryptedPair;
}

// Function to decrypt a pair of characters using the key table
std::string decryptPair(const std::vector<std::vector<char>>& keyTable, char c1, char c2) {
    std::pair<int, int> pos1 = findCharPosition(keyTable, c1);
    std::pair<int, int> pos2 = findCharPosition(keyTable, c2);

    std::string decryptedPair;
    if (pos1.first == pos2.first) {
        decryptedPair.push_back(keyTable[pos1.first][(pos1.second + 4) % 5]);
        decryptedPair.push_back(keyTable[pos2.first][(pos2.second + 4) % 5]);
    } else if (pos1.second == pos2.second) {
        decryptedPair.push_back(keyTable[(pos1.first + 4) % 5][pos1.second]);
        decryptedPair.push_back(keyTable[(pos2.first + 4) % 5][pos2.second]);
    } else {
        decryptedPair.push_back(keyTable[pos1.first][pos2.second]);
        decryptedPair.push_back(keyTable[pos2.first][pos1.second]);
    }
    return decryptedPair;
}

// Function to encrypt the message using the Playfair cipher
std::string encryptMessage(const std::string& message, const std::string& key) {
    // Prepare the message
    std::string preparedMessage = prepareMessage(message);

    // Remove duplicate characters from the key
    std::string uniqueKey = removeDuplicates(key);

    // Generate the key table
    std::vector<std::vector<char>> keyTable(5, std::vector<char>(5));
    generateKeyTable(uniqueKey, keyTable);

    // Encrypt the message
    std::string encryptedMessage;
    for (size_t i = 0; i < preparedMessage.length(); i += 2) {
        char c1 = preparedMessage[i];
        char c2 = (i + 1 < preparedMessage.length()) ? preparedMessage[i + 1] : 'X';
        std::string encryptedPair = encryptPair(keyTable, c1, c2);
        encryptedMessage += encryptedPair;
    }

    return encryptedMessage;
}

// Function to decrypt the message using the Playfair cipher
std::string decryptMessage(const std::string& ciphertext, const std::string& key) {
    // Remove duplicate characters from the key
    std::string uniqueKey = removeDuplicates(key);

    // Generate the key table
    std::vector<std::vector<char>> keyTable(5, std::vector<char>(5));
    generateKeyTable(uniqueKey, keyTable);

    // Decrypt the ciphertext
    std::string decryptedMessage;
    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        char c1 = ciphertext[i];
        char c2 = ciphertext[i + 1];
        std::string decryptedPair = decryptPair(keyTable, c1, c2);
        decryptedMessage += decryptedPair;
    }

    return decryptedMessage;
}
