#include <iostream>
#include "ShoppingItem.h"

ShoppingItem::ShoppingItem() {
    name = "";
    price = 0;
}

ShoppingItem::ShoppingItem(std::string name, double price) {
    this->name = name;
    this->price = price;
}

std::string ShoppingItem::get_name() {
    return name;
}

double ShoppingItem::get_price() {
    return price;
}

void ShoppingItem::set_name(std::string name) {
    this->name = name;
}

void ShoppingItem::set_price(double price) {
    this->price = price;
}

void ShoppingItem::print()  {
    std::cout << name << "\t" << price << std::endl;
}