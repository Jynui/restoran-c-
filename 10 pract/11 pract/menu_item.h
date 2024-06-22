#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <vector>
#include <string>
#include "product.h"

class MenuItem {
public:
    MenuItem(int id, const std::string& name, const std::vector<Product>& ingredients, const std::string& description, double preparationTime, double price);

    void displayInfo() const;

    int getId() const;
    const std::string& getName() const;
    const std::vector<Product>& getIngredients() const;

    void setName(const std::string& name);
    void setIngredients(const std::vector<Product>& ingredients);
    void setDescription(const std::string& description);
    void setPreparationTime(double preparationTime);
    void setPrice(double price);

private:
    int id;
    std::string name;
    std::vector<Product> ingredients;
    std::string description;
    double preparationTime;
    double price;
};

#endif
