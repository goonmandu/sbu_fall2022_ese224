#include <queue>
#include <iostream>

void menu(std::queue<int> &cue) {
    int choice;
    while (choice != 4) {
        std::cout << "Welcome to your very own queue!" << std::endl;
        std::cout << "(1) - Insert an item" << std::endl;
        std::cout << "(2) - Remove the front item" << std::endl;
        std::cout << "(3) - Display the queue" << std::endl;
        std::cout << "(4) - Exit" << std::endl;
        std::cout << "Pick an option: ";
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Enter an int: ";
            std::cin >> choice;
            cue.push(choice);
        } else if (choice == 2) {
            cue.pop();
        } else if (choice == 3) {
            std::queue<int> aux;
            while (!cue.empty()) {
                int curr = cue.front();
                aux.push(curr);
                std::cout << curr << " ";
                cue.pop();
            }
            std::cout << std::endl;
            std::swap(aux, cue);
        } else if (choice == 4) {
            std::cerr << "Goodbye." << std::endl;
            return;
        }
    }
}

int main() {
    std::queue<int> intqueue;
    menu(intqueue);
}