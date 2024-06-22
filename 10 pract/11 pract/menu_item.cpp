#include "menu_item.h"
#include <iostream>
#include <iomanip>

MenuItem::MenuItem(int id, const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price)
    : id(id), name(name), ingredients(ingredients), description(description), preparationTime(preparationTime), price(price) {}

void MenuItem::displayInfo() const {
    std::cout << "ID: " << id
        << "\nНазвание: " << name
        << "\nОписание: " << description
        << "\nВремя приготовления: " << preparationTime << " минут"
        << "\nЦена: " << std::fixed << std::setprecision(2) << price << " руб."
        << "\nИнгредиенты: ";
    for (const auto& ingredient : ingredients) {
        std::cout << ingredient.getName() << " ";
    }
    std::cout << std::endl;
}

int MenuItem::getId() const {
    return id;
}

const std::string& MenuItem::getName() const {
    return name;
}

const std::vector<Product>& MenuItem::getIngredients() const {
    return ingredients;
}

const std::string& MenuItem::getDescription() const {
    return description;
}

double MenuItem::getPreparationTime() const {
    return preparationTime;
}

double MenuItem::getPrice() const {
    return price;
}

void MenuItem::setName(const std::string& name) {
    this->name = name;
}

void MenuItem::setIngredients(const std::vector<Product>& ingredients) {
    this->ingredients = ingredients;
}

void MenuItem::setDescription(const std::string& description) {
    this->description = description;
}

void MenuItem::setPreparationTime(double preparationTime) {
    this->preparationTime = preparationTime;
}

void MenuItem::setPrice(double price) {
    this->price = price;
}
