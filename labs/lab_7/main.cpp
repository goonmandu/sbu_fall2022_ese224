#include <iostream>
#include "Matrix.h"

int main() {
    double m1data[] = {1, 2, 3, 4, 5, 6};
    double m2data[] = {10, 11, 20, 21, 30, 31};
    Matrix m1 = Matrix(2, 3, m1data);
    Matrix m2 = Matrix(3, 2, m2data);

    std::cout << "-- Part 1 --\n";
    std::cout << "Left-hand side matrix:";
    m1.show();
    std::cout << "Right-hand side matrix:";
    m2.show();
    Matrix m3 = m1 * m2;
    std::cout << "Product matrix of LHS * RHS:";
    m3.show();

    std::cout << "\n-- Part 2 --\n";
    double m4data[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::cout << "Matrix of ints 1 - 20:";
    Matrix m4 = Matrix(4, 5, m4data);
    m4.show();
    std::cout << "Same matrix, spirally traversed:\n";
    print_simple_vector(spiral(4, 5, m4data));

    std::cout << "\n-- Part 3 --\n";
    std::cout << "Matrix of ints 1 - 20:";
    m4.show();
    std::cout << "Does the matrix have value 6.9? " << m4.has(6.9) << std::endl;
    std::cout << "Does the matrix have value 14? " << m4.has(14) << std::endl;

    std::cout << "\n-- Part 4 --\n";
    std::vector<std::vector<int>> sudoku_valid = {{5,3,0,0,7,0,0,0,0}
                                                 ,{6,0,0,1,9,5,0,0,0}
                                                 ,{0,9,8,0,0,0,0,6,0}
                                                 ,{8,0,0,0,6,0,0,0,3}
                                                 ,{4,0,0,8,0,3,0,0,1}
                                                 ,{7,0,0,0,2,0,0,0,6}
                                                 ,{0,6,0,0,0,0,2,8,0}
                                                 ,{0,0,0,4,1,9,0,0,5}
                                                 ,{0,0,0,0,8,0,0,7,9}};

    std::vector<std::vector<int>> sudoku_invalid = {{8,3,0,0,7,0,0,0,0}
                                                   ,{6,0,0,1,9,5,0,0,0}
                                                   ,{0,9,8,0,0,0,0,6,0}
                                                   ,{8,0,0,0,6,0,0,0,3}
                                                   ,{4,0,0,8,0,3,0,0,1}
                                                   ,{7,0,0,0,2,0,0,0,6}
                                                   ,{0,6,0,0,0,0,2,8,0}
                                                   ,{0,0,0,4,1,9,0,0,5}
                                                   ,{0,0,0,0,8,0,0,7,9}};
    std::cout << "Is the given testcase valid sudoku valid? " << sudoku_is_valid(sudoku_valid) << std::endl;
    std::cout << "Is the given testcase invalid sudoku valid? " << sudoku_is_valid(sudoku_invalid) << std::endl;
}