#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <string>

class PasswordManager {
public:
    static std::string hashPassword(const std::string& password);
    static std::string encryptPassword(const std::string& password, const std::string& key);
    static std::string decryptPassword(const std::string& encryptedPassword, const std::string& key);
};

#endif // PASSWORDMANAGER_H
