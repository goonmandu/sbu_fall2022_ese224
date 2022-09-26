#include <iostream>
#include <algorithm>

int is_palindrome(std::string);
void string_upper(std::string &str);

int main() {
    int palin_len = 0;
    std::string word;
    std::cout << "Enter a string: ";
    std::cin >> word;
    for (int start = 0; start < word.size(); start++) {
        for (int length = 1; length < word.size() + 1 - start; length++) {
            // std::cout << word.substr(start, length);
            int current = is_palindrome(word.substr(start, length));
            // std::cout << current << std::endl;
            if (current > palin_len) {
                palin_len = current;
            }
        }
    }
    std::cout << "The longest palindrome length is " << palin_len << "." << std::endl;
}

void string_upper(std::string &str) {
    for (int idx = 0; idx < str.size(); idx++) {
        str[idx] = toupper(str[idx]);
    }
}

int is_palindrome(std::string str) {
    string_upper(str);
    std::string copy = str;
    std::reverse(str.begin(), str.end());
    if (str == copy) {
        return str.size();
    } else {
        return 0;
    }
}