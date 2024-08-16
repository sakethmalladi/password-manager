#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <sqlite3.h>
#include <string>

class DatabaseManager {
public:
    DatabaseManager(const std::string& dbName);
    ~DatabaseManager();

    void createTables();
    void saveUserCredentials(const std::string& username, const std::string& password);
    void saveEncryptedPassword(const std::string& accountName, const std::string& username, const std::string& encryptedPassword);
    void retrievePasswords(const std::string& key);

private:
    sqlite3* db;
    void openDatabase(const std::string& dbName);
    void closeDatabase();
};

#endif // DATABASEMANAGER_H
