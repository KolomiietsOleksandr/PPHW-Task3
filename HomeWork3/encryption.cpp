#include <iostream>
#include <string>
#include <sstream>

const std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 !@#$%^&*()_+-=[]{}|;':,.<>?";
const int alphabetSize = alphabet.size();

long long getValidKey(const std::string &keyString) {
    std::stringstream keyStream(keyString);
    long long key = 0;
    keyStream >> key;
    return key % alphabetSize;
}

std::string performCipher(const std::string &inputText, const std::string &keyString, bool encrypt) {
    long long key = getValidKey(keyString);
    std::string result = inputText;

    for (size_t i = 0; i < inputText.length(); i++) {
        char currentChar = inputText[i];
        size_t charIndex = alphabet.find(currentChar);

        if (charIndex != std::string::npos) {
            int offset = encrypt ? key : -key;
            char cipheredChar = alphabet[(charIndex + offset + alphabetSize) % alphabetSize];
            result[i] = cipheredChar;
        }
    }

    return result;
}

extern "C" void encrypt() {
    std::string inputText;
    std::string keyString;

    std::cout << "Enter the text to encrypt: ";
    std::getline(std::cin >> std::ws, inputText);

    std::cout << "Enter the encryption key: ";
    std::getline(std::cin >> std::ws, keyString);

    std::string encryptedText = performCipher(inputText, keyString, true);

    std::cout << "Encrypted text: " << encryptedText << std::endl;
}

extern "C" void decrypt() {
    std::string inputText;
    std::string keyString;

    std::cout << "Enter the text to decrypt: ";
    std::getline(std::cin >> std::ws, inputText);

    std::cout << "Enter the decryption key: ";
    std::getline(std::cin >> std::ws, keyString);

    std::string decryptedText = performCipher(inputText, keyString, false);

    std::cout << "Decrypted text: " << decryptedText << std::endl;
}
