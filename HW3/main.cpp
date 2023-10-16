#include <iostream>
#include <cstring>

char* encrypt(char* rawText, int key) {
    if (rawText == nullptr) {
        return nullptr;
    }

    int textLength = strlen(rawText);
    char* encryptedText = new char[textLength + 1];

    for (int i = 0; i < textLength; i++) {
        if (isalpha(rawText[i])) {
            char base = (isupper(rawText[i]) ? 'A' : 'a');
            encryptedText[i] = base + (rawText[i] - base + key) % 26;
        } else {
            encryptedText[i] = rawText[i];
        }
    }

    encryptedText[textLength] = '\0';
    return encryptedText;
}

char* decrypt(char* encryptedText, int key) {
    if (encryptedText == nullptr) {
        return nullptr;
    }

    int textLength = strlen(encryptedText);
    char* decryptedText = new char[textLength + 1];

    for (int i = 0; i < textLength; i++) {
        if (isalpha(encryptedText[i])) {
            char base = (isupper(encryptedText[i]) ? 'A' : 'a');
            int shift = (encryptedText[i] - base - key + 26) % 26;
            decryptedText[i] = base + shift;
        } else {
            decryptedText[i] = encryptedText[i];
        }
    }

    decryptedText[textLength] = '\0';
    return decryptedText;
}

int main() {
    char choice;

    while (true) {
        std::cout << "Encrypt (e) or decrypt (d) [q to quit]? ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 'q') {
            break; // Вихід з циклу при введенні 'q'
        } else if (choice == 'e' || choice == 'd') {
            char inputText[100];
            int key;

            if (choice == 'e') {
                std::cout << "Enter the text to encrypt: ";
            } else {
                std::cout << "Enter the text to decrypt: ";
            }

            std::cin.getline(inputText, sizeof(inputText));

            std::cout << "Enter the encryption/decryption key: ";
            std::cin >> key;
            std::cin.ignore();

            if (choice == 'e') {
                char* encryptedText = encrypt(inputText, key);
                std::cout << "Encrypted text: " << encryptedText << std::endl;
                delete[] encryptedText;
            } else {
                char* decryptedText = decrypt(inputText, key);
                std::cout << "Decrypted text: " << decryptedText << std::endl;
                delete[] decryptedText;
            }
        } else {
            std::cerr << "Invalid choice. Use 'e' for encryption, 'd' for decryption, or 'q' to quit." << std::endl;
        }
    }

    return 0;
}
