#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <iostream>
#include "menu.h"

enum OrderStatus {
    NEW,
    PAID,
    IN_PROGRESS,
    READY_FOR_PICKUP,
    COMPLETED
};

class Order {
public:
    Order(int id);

    void addItem(const MenuItem& item);
    void display() const; 
    void setStatus(OrderStatus status);
    OrderStatus getStatus() const;
    int getId() const;
    const std::vector<MenuItem>& getItems() const;

private:
    int id;
    std::vector<MenuItem> items;
    OrderStatus status;
};

#endif 