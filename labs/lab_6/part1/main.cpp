#include <vector>
#include <iostream>

std::string longest_common_prefix(std::vector<std::string> &strings);

int main() {
    std::cout << "/*   PART 1   */" << std::endl;
    std::vector<std::string> inputs1 = {
        "flower",
        "flow",
        "flight"
    };
    std::vector<std::string> inputs2 = {
        "dog",
        "racecar",
        "car"
    };

    std::cout << "Longest Common Prefix of Testcase1: " << longest_common_prefix(inputs1) << std::endl;
    std::cout << "Longest Common Prefix of Testcase2: " << longest_common_prefix(inputs2) << std::endl;
}

std::string longest_common_prefix(std::vector<std::string> &strings) {
    int min_len = strings[0].size();
    int common_up_to;
    bool has_deviant = false;
    for (std::string str : strings) {
        if (str.size() < min_len) {
            min_len = str.size();
        }
    }
    for (int c_idx = 0; c_idx < min_len; c_idx++) {
        for (int s_idx = 0; s_idx < strings.size() - 1; s_idx++) {
            if (strings[s_idx][c_idx] != strings[s_idx+1][c_idx]) {
                has_deviant = true;
            }
        }
        if (has_deviant) {
            common_up_to = c_idx;
            break;
        }
    }
    return strings[0].substr(0, common_up_to);
}