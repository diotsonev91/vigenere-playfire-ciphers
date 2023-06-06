#include <string>

// Function to prepare the message by removing non-alphabetic characters and converting to uppercase
std::string prepareMessage(const std::string& message) {
    std::string preparedMessage;

    for (char c : message) {
        if (isalpha(c))
            preparedMessage.push_back(toupper(c));
    }
    return preparedMessage;
}