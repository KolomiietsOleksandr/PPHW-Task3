#include <iostream>
#include <dlfcn.h>

int main() {
    while (true) {
        void* library = dlopen("/Users/zakerden1234/Desktop/PPHW-Task3/HomeWork3/encryption.dylib", RTLD_LAZY);

        if (!library) {
            std::cerr << "Failed to load the library: " << dlerror() << std::endl;
            return 1;
        }

        typedef void (*EncryptFunction)();
        typedef void (*DecryptFunction)();

        EncryptFunction encrypt = (EncryptFunction)dlsym(library, "encrypt");
        DecryptFunction decrypt = (DecryptFunction)dlsym(library, "decrypt");

        if (!encrypt || !decrypt) {
            std::cerr << "Failed to load functions: " << dlerror() << std::endl;
            return 1;
        }

        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Encrypt" << std::endl;
        std::cout << "2. Decrypt" << std::endl;
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            encrypt();
        } else if (choice == 2) {
            decrypt();
        } else {
            std::cout << "Invalid choice." << std::endl;
        }

        dlclose(library);
    }

    return 0;
}
