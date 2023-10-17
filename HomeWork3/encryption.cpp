#include <iostream>
#include <cstring>
#include <cctype>

extern "C" void encrypt() {
    char inputText[100];
    int key;

    std::cout << "Enter the text to encrypt: ";
    std::cin.getline(inputText, sizeof(inputText));

    std::cout << "Enter the encryption key 1-26: ";
    std::cin >> key;
    std::cin.ignore();

    int textLength = strlen(inputText);
    char* encryptedText = new char[textLength + 1];

    for (int i = 0; i < textLength; i++) {
        if (isalpha(inputText[i])) {
            char base = (isupper(inputText[i]) ? 'A' : 'a');
            encryptedText[i] = base + (inputText[i] - base + key) % 26;
        } else {
            encryptedText[i] = inputText[i];
        }
    }

    encryptedText[textLength] = '\0';
    std::cout << "Encrypted text: " << encryptedText << std::endl;
    delete[] encryptedText;
}

extern "C" void decrypt() {
    char inputText[100];
    int key;

    std::cout << "Enter the text to decrypt: ";
    std::cin.getline(inputText, sizeof(inputText));

    std::cout << "Enter the decryption key 1-26: ";
    std::cin >> key;
    std::cin.ignore();

    int textLength = strlen(inputText);
    char* decryptedText = new char[textLength + 1];

    for (int i = 0; i < textLength; i++) {
        if (isalpha(inputText[i])) {
            char base = (isupper(inputText[i]) ? 'A' : 'a');
            int shift = (inputText[i] - base - key + 26) % 26;
            decryptedText[i] = base + shift;
        } else {
            decryptedText[i] = inputText[i];
        }
    }

    decryptedText[textLength] = '\0';
    std::cout << "Decrypted text: " << decryptedText << std::endl;
    delete[] decryptedText;
}