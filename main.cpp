#include "DatabaseManager.h"
#include "PasswordManager.h"
#include <iostream>
#include <string>

int main() {
    DatabaseManager dbManager("password_manager.db");
    dbManager.createTables();

    std::string masterPassword;
    std::cout << "Enter your master password: ";
    std::cin >> masterPassword;

    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;

    dbManager.saveUserCredentials(username, masterPassword);

    while (true) {
        std::cout << "\nPassword Manager Options:\n";
        std::cout << "1. Store a new password\n";
        std::cout << "2. Retrieve passwords\n";
        std::cout << "3. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string accountName, accountUsername, accountPassword;
            std::cout << "Enter the account name: ";
            std::cin >> accountName;
            std::cout << "Enter the account username: ";
            std::cin >> accountUsername;
            std::cout << "Enter the account password: ";
            std::cin >> accountPassword;

            std::string encryptedPassword = PasswordManager::encryptPassword(accountPassword, masterPassword);
            dbManager.saveEncryptedPassword(accountName, accountUsername, encryptedPassword);
        } else if (choice == 2) {
            dbManager.retrievePasswords(masterPassword);
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
