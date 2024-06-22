#include "order.h"
#include <iostream>

Order::Order(int id) : id(id), status(OrderStatus::NEW) {}

void Order::addItem(const MenuItem& item) {
    items.push_back(item);
}

void Order::display() const {
    std::cout << "Order ID: " << id << "\nStatus: " << getStatusString() << "\nItems:\n";
    for (const auto& item : items) {
        item.displayInfo();
    }
}

void Order::setStatus(OrderStatus status) {
    this->status = status;
}

OrderStatus Order::getStatus() const {
    return status;
}

int Order::getId() const {
    return id;
}

const std::vector<MenuItem>& Order::getItems() const {
    return items;
}

std::string Order::getStatusString() const {
    switch (status) {
    case OrderStatus::NEW:
        return "New";
    case OrderStatus::IN_PROGRESS:
        return "In Progress";
    case OrderStatus::COMPLETED:
        return "Completed";
    case OrderStatus::CANCELLED:
        return "Cancelled";
    default:
        return "Unknown";
    }
}
