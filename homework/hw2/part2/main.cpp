#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>

typedef struct Result {
    double answer;
    int correct;
} Result;

int take_operation() {
    int input;
    std::cout << "Enter 1 - 5 to select an operation to be quizzed on: " << std::endl;
    std::cout << "1 - Addition" << std::endl;
    std::cout << "2 - Subtraction" << std::endl;
    std::cout << "3 - Multiplication" << std::endl;
    std::cout << "4 - Division" << std::endl;
    std::cout << "5 - Exit" << std::endl;
    std::cout << "Your choice is: ";
    std::cin >> input;
    // std::cout << input << std::endl;
    return input;
}

Result quiz(int* operands, unsigned char operation) {
    Result result = {0, 0};
    double guess;
    // std::cout << operation << std::endl;
    if (operation < 1 || operation > 5) {
        std::cerr << "Incorrect operation selected. Exiting." << std::endl;
        exit(1);
    }
    if (operation == 5) {
        std::cerr << "Goodbye." << std::endl;
        exit(0);
    }
    std::cout << "What is " << operands[0];
    switch(operation) {
        case 1:
            std::cout << " + ";
            result.answer = operands[0] + operands[1];
            break;
        case 2:
            std::cout << " - ";
            result.answer = operands[0] - operands[1];
            break;
        case 3:
            std::cout << " x ";
            result.answer = operands[0] * operands[1];
            break;
        case 4:
            std::cout << " / ";
            result.answer = (double) operands[0] / operands[1];
            break;
    }
    std::cout << operands[1] << "?" << std::endl;
    std::cout << "Your answer: ";
    std::cin >> guess;
    if (fabs(result.answer - guess) < 0.001) {
        result.correct = 1;
    } else {
        result.correct = 0;
    }
    return result;
}

int main() {

    srand(time(NULL));
    while (1) {
        int operands[2] = {(rand() % 65535), (rand() % 65535)};

        Result result = quiz(operands, take_operation());
        if (result.correct) {
            std::cout << "Correct! ";
        } else {
            std::cout << "Incorrect! ";
        }
        std::cout << std::fixed << std::setprecision(5) << std::showpoint << std::fixed\
                  << "The exact answer was " << result.answer << "." << std::endl << std::endl;
    }
}