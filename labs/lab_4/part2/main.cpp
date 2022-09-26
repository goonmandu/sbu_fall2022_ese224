#include <iostream>
#include <cctype>

void string_upper(std::string&);

int main() {
    std::string input;

    while (1) {
        std::cout << "Enter a string: ";
        std::cin >> input;
        if (input == "q") {
            std::cout << "Goodbye." << std::endl;
            break;
        }
        string_upper(input);
        std::cout << input << std::endl;
    }
}

void string_upper(std::string &str) {
    for (int idx = 0; idx < str.size(); idx++) {
        str[idx] = toupper(str[idx]);
    }
}