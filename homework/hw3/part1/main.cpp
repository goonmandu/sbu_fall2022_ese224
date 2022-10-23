#include <iostream>
#include <cstring>
#include <vector>
#include <string>

void print_vec(std::vector<std::string> vec);
std::vector<std::string> lexicosort(std::vector<std::string> &vec);
std::vector<std::string> merge(std::vector<std::string> &vec1, std::vector<std::string> &vec2);

int main() {
    std::vector<std::string> list = {
        "OMEGALUL",
        "PeepoHappy",
        "Pepega",
        "Jebaited",
        "xqcL"
    };

    print_vec(lexicosort(list));
}

void print_vec(std::vector<std::string> vec) {
    for (std::string str : vec) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
}

std::vector<std::string> merge(std::vector<std::string> &vec1, std::vector<std::string> &vec2) {
    std::vector<std::string> vec;

    while (vec1.size() && vec2.size()) {
        if (strcmp(vec1[0].c_str(), vec2[0].c_str()) < 0) {
            vec.push_back(vec1[0]);
            vec1.erase(vec1.begin());
        } else {
            vec.push_back(vec2[0]);
            vec2.erase(vec2.begin());
        }
    }
    if (vec1.size()) {
        while (vec1.size()) {
            vec.push_back(vec1[0]);
            vec1.erase(vec1.begin());
        }
    } else {
        while (vec2.size()) {
            vec.push_back(vec2[0]);
            vec2.erase(vec2.begin());
        }
    }
    return vec;
}

std::vector<std::string> lexicosort(std::vector<std::string> &vec) {
    if (vec.size() == 1) {
        return vec;
    }
    int const half = vec.size() / 2;
    std::vector<std::string> firsthalf(vec.begin(), vec.begin() + half);
    std::vector<std::string> secondhalf(vec.begin() + half, vec.end());

    firsthalf = lexicosort(firsthalf);
    secondhalf = lexicosort(secondhalf);

    return merge(firsthalf, secondhalf);
}