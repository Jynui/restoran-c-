#include "menu.h"
#include <algorithm>
#include <iostream>


Menu::Menu() : nextId(1) {}

void Menu::addItem(const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price) {
    items.emplace_back(nextId++, name, ingredients, description, preparationTime, price);
}

bool Menu::editItem(int id, const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price) {
    auto it = std::find_if(items.begin(), items.end(), [id](const MenuItem& item) {
        return item.getId() == id;
        });

    if (it != items.end()) {
        it->setName(name);
        it->setIngredients(ingredients);
        it->setDescription(description);
        it->setPreparationTime(preparationTime);
        it->setPrice(price);
        return true;
    }
    return false;
}

bool Menu::removeItem(int id) {
    auto it = std::remove_if(items.begin(), items.end(), [id](const MenuItem& item) {
        return item.getId() == id;
        });

    if (it != items.end()) {
        items.erase(it, items.end());
        return true;
    }
    return false;
}

void Menu::displayMenu() const {
    for (const auto& item : items) {
        item.displayInfo();
    }
}

MenuItem* Menu::getItem(int id) {
    auto it = std::find_if(items.begin(), items.end(), [id](const MenuItem& item) {
        return item.getId() == id;
        });

    return (it != items.end()) ? &(*it) : nullptr;
}

void Menu::setProducts(const std::vector<Product>& products) {
    this->products = products;
}

const std::vector<Product>& Menu::getProducts() const {
    return products;
}

std::vector<Product>& Menu::getProducts() {
    return products;
}
