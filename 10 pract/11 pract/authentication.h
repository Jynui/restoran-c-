#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <vector>
#include <string>
#include "user.h"

class Authentication {
private:
    std::vector<User> users;

public:
    bool login(const std::string& login, const std::string& password, std::string& role); 
    void addUser(const User& user);
    void removeUser(const std::string& login);
    void editUser(const std::string& login, const User& newUser);
    const std::vector<User>& getUsers() const;
};

#endif