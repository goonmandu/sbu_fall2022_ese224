#pragma once
#include <string>

class ShoppingItem {
    private:
        std::string name;
        double price;

    public:
        ShoppingItem();
        ShoppingItem(std::string name, double price);
        std::string get_name();
        double get_price();
        void set_name(std::string name);
        void set_price(double price);
        void print();
        void print_name();
};