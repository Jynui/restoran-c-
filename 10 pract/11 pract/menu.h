#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "product.h"
#include "menu_item.h"

class Menu {
public:
    void addItem(const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price);
    void editItem(int id, const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price);
    void removeItem(int id);
    void displayMenu() const;
    MenuItem* getItem(int id);

    void setProducts(const std::vector<Product>& products);
    const std::vector<Product>& getProducts() const;
    std::vector<Product>& getProducts(); 

private:
    std::vector<MenuItem> items;
    std::vector<Product> products;
};

#endif