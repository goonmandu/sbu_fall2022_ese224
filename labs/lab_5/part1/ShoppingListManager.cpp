#include <iostream>
#include "ShoppingList.h"

int main() {
    char input;
    std::cout << "Welcome to ShoppingListManager!\n";
    ShoppingList list = ShoppingList();
    if (list.open_file_and_check(std::cin)) {
        std::cout << "Successfully opened file.\n";
    } else {
        std::cerr << "Failed to open file!\n";
        exit(1);
    }
    list.fill_shopping_list();

    while (1) {
        control();
        std::cin >> input;
        if (input == 'q') {
            std::cout << "Goodbye.\n";
            return 0;
        }
        std::cout << "\n";
        switch (input) {
            case 'a':
                list.add_item(std::cin);
                break;
            case 'e':
                list.print_most_expensive();
                break;
            case 'i':
                list.item_exists(std::cin);
                break;
            case 'p':
                list.print_all();
                break;
            case 's':
                list.sort_price();
                break;
            case 't':
                list.print_transpose();
                break;
            default:
                std::cout << "Please choose a valid option.\n";
        }
        list.fill_shopping_list();
    }
}
