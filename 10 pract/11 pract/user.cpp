#include "user.h"
#include <iostream>

User::User(int id, const std::string& role, const std::string& surname, const std::string& name, const std::string& patronymic, const std::string& login, const std::string& password)
    : id(id), role(role), surname(surname), name(name), patronymic(patronymic), login(login), password(password) {}

const std::string& User::getRole() const {
    return role;
}

const std::string& User::getLogin() const {
    return login;
}

const std::string& User::getPassword() const {
    return password;
}


Guest::Guest(int id, const std::string& name)
    : id(id), name(name) {}

void Guest::addOrder(const Order& order) {
    orders.push_back(order);
}

void Guest::displayOrders() const {
    for (const auto& order : orders) {
        order.display(); 
    }
}

const std::vector<Order>& Guest::getOrders() const {
    return orders;
}