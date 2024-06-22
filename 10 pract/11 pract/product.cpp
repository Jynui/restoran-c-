#include "product.h"

Product::Product(int id, const std::string& name, double cost, int quantity)
    : id(id), name(name), cost(cost), quantity(quantity) {}

int Product::getId() const {
    return id;
}

const std::string& Product::getName() const {
    return name;
}

double Product::getCost() const {
    return cost;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}