#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "order.h"

class User {
public:
    User(int id, const std::string& role, const std::string& surname, const std::string& name, const std::string& patronymic, const std::string& login, const std::string& password);

    const std::string& getRole() const;
    const std::string& getLogin() const;
    const std::string& getPassword() const;

private:
    int id;
    std::string role;
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string login;
    std::string password;
};

class Guest {
public:
    Guest(int id, const std::string& name);

    void addOrder(const Order& order);
    void displayOrders() const;
    const std::vector<Order>& getOrders() const;  

private:
    int id;
    std::string name;
    std::vector<Order> orders;
};

#endif