#include "authentication.h"
#include <algorithm>
#include <iostream>

bool Authentication::login(const std::string& login, const std::string& password, std::string& role) const {
    auto it = std::find_if(users.begin(), users.end(), [&](const User& user) {
        return user.getLogin() == login && user.getPassword() == password;
        });

    if (it != users.end()) {
        role = it->getRole();
        return true;
    }
    return false;
}

void Authentication::addUser(const User& user) {
    if (std::none_of(users.begin(), users.end(), [&](const User& u) { return u.getLogin() == user.getLogin(); })) {
        users.push_back(user);
    }
    else {
        std::cerr << "User with login " << user.getLogin() << " already exists.\n";
    }
}

bool Authentication::removeUser(const std::string& login) {
    auto it = std::remove_if(users.begin(), users.end(), [&](const User& user) {
        return user.getLogin() == login;
        });

    if (it != users.end()) {
        users.erase(it, users.end());
        return true;
    }
    return false;
}

bool Authentication::editUser(const std::string& login, const User& newUser) {
    auto it = std::find_if(users.begin(), users.end(), [&](const User& user) {
        return user.getLogin() == login;
        });

    if (it != users.end()) {
        *it = newUser;
        return true;
    }
    return false;
}

const std::vector<User>& Authentication::getUsers() const {
    return users;
}
