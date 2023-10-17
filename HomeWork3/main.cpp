#include <iostream>
#include <dlfcn.h>

int main() {
    void* encryptionLib = dlopen("/Users/zakerden1234/Desktop/PPHW-Task3/HomeWork3/encryption.dylib", RTLD_LAZY);

    if (!encryptionLib) {
        std::cerr << "Failed to load the encryption library." << std::endl;
        return 1;
    }

    void (*encrypt)() = (void (*)())dlsym(encryptionLib, "encrypt");
    void (*decrypt)() = (void (*)())dlsym(encryptionLib, "decrypt");

    if (!encrypt || !decrypt) {
        std::cerr << "Failed to get function pointers." << std::endl;
        return 1;
    }

    char choice;

    while (true) {
        std::cout << "Encrypt (e) or decrypt (d) [q to quit]? ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 'q') {
            break;
        } else if (choice == 'e') {
            encrypt();
        } else if (choice == 'd') {
            decrypt();
        } else {
            std::cerr << "Invalid choice. Use 'e' for encryption, 'd' for decryption, or 'q' to quit." << std::endl;
        }
    }

    dlclose(encryptionLib);

    return 0;
}
