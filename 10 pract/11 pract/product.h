#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    Product(int id, const std::string& name, double cost, int quantity);

    int getId() const;
    const std::string& getName() const;
    double getCost() const;
    int getQuantity() const;
    void setQuantity(int quantity);

private:
    int id;
    std::string name;
    double cost;
    int quantity; 
};

#endif    
