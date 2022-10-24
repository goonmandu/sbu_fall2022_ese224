#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    for (int i = 0; i < rows; ++i) {
        this->data.push_back({});
        for (int j = 0; j < columns; ++j) {
            this->data[i].push_back(0);
        }
    }
}

Matrix::Matrix(int rows, int columns, double array[]) {
    this->rows = rows;
    this->columns = columns;
    double *arrptr = array;
    for (int i = 0; i < rows; ++i) {
        this->data.push_back({});
        for (int j = 0; j < columns; ++j) {
            this->data[i].push_back(*(arrptr++));
        }
    }
}

void Matrix::show() {
    std::cout << std::endl;
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->columns; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Matrix Matrix::operator* (const Matrix rhs) {
    Matrix result = Matrix(this->rows, rhs.columns);
    for (int i = 0; i < result.rows; ++i) {
        for (int j = 0; j < result.columns; ++j) {
            for (int iter = 0; iter < rhs.rows; ++iter) {
                result.data[i][j] += this->data[i][iter] * rhs.data[iter][j];
            }
        }
    }
    return result;
}

int Matrix::get_rows() {
    return rows;
}

int Matrix::get_columns() {
    return columns;
}

double Matrix::number_at(int row, int col) {
    return this->data[row][col];
}

std::vector<double> spiral(int rows, int columns, double array[]) {
    Matrix matrix = Matrix(rows, columns, array);
    int row_start = 0, row_end = matrix.get_rows() - 1;
    int col_start = 0, col_end = matrix.get_columns() - 1;
    std::vector<double> result;
    
    while(row_start < row_end && col_start < col_end) {
        for (int i = col_start; i <= col_end; i = i + 1) {
            result.push_back(matrix.number_at(row_start, i));
        }    
        row_start++;

        for (int i = row_start; i <= row_end; i = i + 1) {
            result.push_back(matrix.number_at(i, col_end));
        }    
        col_end--;

        if (row_start <= row_end) {
            for (int i = col_end; i >= col_start; i = i - 1) {
                result.push_back(matrix.number_at(row_end, i));
            }    
            row_end--;
        }

        if (col_start <= col_end) {
            for (int i = row_end; i >= row_start; i = i - 1) {
                result.push_back(matrix.number_at(i, col_start));
            }
            col_start++;
        }
    }
    return result;
}

void print_simple_vector(std::vector<double> vec) {
    for (double item : vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

bool Matrix::has(double target) {
    int row_to_search = vector_starts_with(this->data, target, 0, this->data.size() - 1);
    if (row_to_search < 0) {
        return false;
    }
    int pos = value_in_vector(this->data[row_to_search], target, 0, this->columns - 1);
    return pos < 0 ? false : true;
}

int value_in_vector(std::vector<double> vec, double target, int start, int end) {
    if (start <= end) {
        int mid = (start + end) / 2;
        if (vec[mid] == target) {
            return mid;
        }
        if (vec[mid] > target) {
            return value_in_vector(vec, target, start, mid - 1);
        }
        if (vec[mid] < target) {
            return value_in_vector(vec, target, mid + 1, end);
        }
    }
    return -1;
}

int vector_starts_with(std::vector<std::vector<double>> vec, double target, int start, int end) {
    if (start <= end) {
        int mid = (start + end) / 2;
        if (vec[mid][0] == target) {
            return mid;
        }
        if (vec[mid][0] > target) {
            return vector_starts_with(vec, target, start, mid - 1);
        }
        if (vec[mid][0] < target) {
            return vector_starts_with(vec, target, mid + 1, end);
        }
    }
    return start - 1;
}

bool sudoku_is_valid(std::vector<std::vector<int>> sudoku) {
    for (int i = 0; i < 9; ++i) {
        if (has_duplicate_nonzero(sudoku[i])) {
            return false;
        }
    }
    for (int j = 0; j < 9; ++j) {
        std::vector<int> column_vector;
        for (int i = 0; i < 9; ++i) {
            column_vector.push_back(sudoku[i][j]);
        }
        if (has_duplicate_nonzero(column_vector)) {
            return false;
        }
    }
    for (int i = 0; i < 7; i += 3) {
        for (int j = 0; j < 7; j += 3) {
            std::vector<int> unraveled;
            for (int inside_i = 0; inside_i < 3; ++inside_i) {
                for (int inside_j = 0; inside_j < 3; ++inside_j) {
                    unraveled.push_back(sudoku[i+inside_i][j+inside_j]);
                }
            }
            if (has_duplicate_nonzero(unraveled)) {
                return false;
            }
        }
    }
    return true;
}

bool has_duplicate_nonzero(std::vector<int> vec) {
    std::vector<int> seen;
    for (int item : vec) {
        for (int rember : seen) {
            if (item == rember) {
                return true;
            }
        }
        if (item) {
            seen.push_back(item);
        }
    }
    return false;
}