#pragma once
#include <fstream>
#include <vector>
#include "ShoppingItem.h"

void control();
void swap(ShoppingItem &, ShoppingItem &);

class ShoppingList {
    private:
        std::string file_name;
        std::fstream my_file;
        // std::string most_expensive;  NOT NECESSARY FOR PROPER FUNCTION
        std::string name;
        std::vector<ShoppingItem> items_list;
        // double price;                NOT NECESSARY FOR PROPER FUNCTION
        // double max_price;            NOT NECESSARY FOR PROPER FUNCTION
    
    public:
        // ShoppingList();
        bool open_file_and_check(std::istream &in);
        void fill_shopping_list();
        bool item_exists(std::istream &in);
        void add_item(std::istream &in);
        void print_most_expensive();
        void print_all();
        void print_transpose();
        void sort_price();
        void save(std::string);
};