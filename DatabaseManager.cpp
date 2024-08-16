#include "DatabaseManager.h"
#include "PasswordManager.h"
#include <iostream>

DatabaseManager::DatabaseManager(const std::string& dbName) {
    openDatabase(dbName);
}

DatabaseManager::~DatabaseManager() {
    closeDatabase();
}

void DatabaseManager::openDatabase(const std::string& dbName) {
    int exit = sqlite3_open(dbName.c_str(), &db);
    if (exit) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        exit(1);
    }
}

void DatabaseManager::closeDatabase() {
    sqlite3_close(db);
}

void DatabaseManager::createTables() {
    std::string createUsersTable = "CREATE TABLE IF NOT EXISTS USERS("
                                   "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                   "USERNAME TEXT NOT NULL, "
                                   "HASHED_PASSWORD TEXT NOT NULL);";

    std::string createPasswordsTable = "CREATE TABLE IF NOT EXISTS PASSWORDS("
                                       "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                       "ACCOUNT_NAME TEXT NOT NULL, "
                                       "USERNAME TEXT NOT NULL, "
                                       "ENCRYPTED_PASSWORD TEXT NOT NULL);";

    sqlite3_exec(db, createUsersTable.c_str(), NULL, 0, NULL);
    sqlite3_exec(db, createPasswordsTable.c_str(), NULL, 0, NULL);
}

void DatabaseManager::saveUserCredentials(const std::string& username, const std::string& password) {
    std::string hashedPassword = PasswordManager::hashPassword(password);
    std::string sql = "INSERT INTO USERS (USERNAME, HASHED_PASSWORD) VALUES ('" + username + "', '" + hashedPassword + "');";
    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}

void DatabaseManager::saveEncryptedPassword(const std::string& accountName, const std::string& username, const std::string& encryptedPassword) {
    std::string sql = "INSERT INTO PASSWORDS (ACCOUNT_NAME, USERNAME, ENCRYPTED_PASSWORD) VALUES ('" + accountName + "', '" + username + "', '" + encryptedPassword + "');";
    sqlite3_exec(db, sql.c_str(), 0, 0, 0);
}

void DatabaseManager::retrievePasswords(const std::string& key) {
    std::string sql = "SELECT ACCOUNT_NAME, USERNAME, ENCRYPTED_PASSWORD FROM PASSWORDS;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string accountName = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            std::string username = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            std::string encryptedPassword = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));

            std::string decryptedPassword = PasswordManager::decryptPassword(encryptedPassword, key);
            std::cout << "Account: " << accountName << ", Username: " << username << ", Password: " << decryptedPassword << std::endl;
        }
    }
    sqlite3_finalize(stmt);
}
