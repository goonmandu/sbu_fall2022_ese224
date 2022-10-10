#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "ShoppingList.h"

bool ShoppingList::open_file_and_check(std::istream &in) {
    std::string filename;
    std::cout << "Enter a file name to open: ";
    in >> filename;
    if (filename != "itemCatalog.txt") {
        std::cout << "Incorrect file name!\n";
        exit(1);
    }
    my_file.open(filename);
    return my_file.is_open();
}

void ShoppingList::fill_shopping_list() {
    std::string name;
    double price;
    items_list.clear();
    my_file.seekg(0);
    while (!my_file.eof()) {
        my_file >> name >> price;
        items_list.push_back(ShoppingItem(name, price));
    }
}

bool ShoppingList::item_exists(std::istream &in) {
    std::string name;
    std::cout << "Enter a product name to search: ";
    in >> name;
    for (ShoppingItem item : items_list) {
        if (name == item.get_name()) {
            std::cout << name << " exists. Its price is " << item.get_price() << "\n";
            return 1;
        }
    }
    std::cout << name << " does not exist.\n";
    return 0;
}

void ShoppingList::add_item(std::istream &in) {
    std::string name;
    double price;
    std::cout << "Enter a product name and price: ";
    in >> name >> price;
    items_list.push_back(ShoppingItem(name, price));
    std::cout << "Successfully added " << name << ", Price " << price << "\n";
    save(name + " " + std::to_string(price));
}

void ShoppingList::print_most_expensive() {
    ShoppingItem max = items_list[0];
    for (ShoppingItem item : items_list) {
        if (item.get_price() > max.get_price()) {
            max = item;
        }
    }
    std::cout << "Most expensive item is " << max.get_name() << ", Price " << max.get_price() << "\n";
}

void ShoppingList::print_all() {
    for (ShoppingItem item : items_list) {
        item.print();
    }
}

void ShoppingList::print_transpose() {
    int max_width = 0;
    for (ShoppingItem item : items_list) {
        if (max_width < item.get_name().length()) {
            max_width = item.get_name().length();
        }
        if (max_width < std::to_string(item.get_price()).length()) {
            max_width = std::to_string(item.get_price()).length();
        }
    }
    for (ShoppingItem item : items_list) {
        std::cout << std::setw(max_width + 1) << std::left;
        std::cout << item.get_name();
    }
    std::cout << "\n";
    for (ShoppingItem item : items_list) {
        std::cout << std::setw(max_width + 1) << std::left;
        std::cout << item.get_price();
    }
    std::cout << "\n";
}

void swap(ShoppingItem &i1, ShoppingItem &i2) {
    ShoppingItem temp = i1;
    i1 = i2;
    i2 = temp;
}

void ShoppingList::sort_price() {
    int max_idx;
    ShoppingItem temp = ShoppingItem();
    int len = items_list.size();
    for (int i = 0; i < len; i++) {  // step by step
        max_idx = i;
        for (int j = i + 1; j < len; j++) {  // look for minimum
            if (items_list[j].get_price() >= items_list[max_idx].get_price()) {
                max_idx = j;
            }
        }
        swap(items_list[max_idx], items_list[i]);
    }
    this->print_all();
}

void control() {
    std::cout << "\nPick an option:\n\n";
    std::cout << "(a) - add item and price\n";
    std::cout << "(e) - print most expensive\n";
    std::cout << "(i) - check if item name exists\n";
    std::cout << "(p) - print all items\n";
    std::cout << "(s) - print in price descending order\n";
    std::cout << "(t) - print transpose format\n";
    std::cout << "(q) - quit app\n\n";
    std::cout << "Your choice: ";
}

void ShoppingList::save(std::string entry) {
    my_file.seekg(0, std::ios::end);
    my_file << "\n" << entry;
}