#pragma once
#include <vector>

class Matrix {
    private:
        std::vector<std::vector<double>> data;
        int rows;
        int columns;

    public:
        Matrix(int rows, int columns);
        Matrix(int rows, int columns, double array[]);
        void show();
        Matrix operator* (Matrix rhs);
        bool has(double target);
        int get_rows();
        int get_columns();
        double number_at(int row, int col);
};

std::vector<double> spiral(int rows, int columns, double array[]);
bool seen_everything(std::vector<int> vec);
int value_in_vector(std::vector<double> vec, double target, int start, int end);
int vector_starts_with(std::vector<std::vector<double>> vec, double target, int start, int end);
bool has_duplicate_nonzero(std::vector<int> row);
bool sudoku_is_valid(std::vector<std::vector<int>> sudoku);
bool has_duplicate_nonzero(std::vector<int> vec);
void print_simple_vector(std::vector<double> vec);