#include <iostream>
#include <cstdlib>

int win(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'X' ||\
            board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 'X') {
            return 1;
        }
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] == 'O' ||\
            board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] == 'O') {
            return 2;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'X' ||\
        board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'X') {
        return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] == 'O' ||\
        board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] == 'O') {
        return 2;
    }
    bool is_filled = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ('X' != board[i][j] && 'O' != board[i][j]) {
                is_filled = false;
            }
        }
    }
    if (is_filled) {
        return 3;
    }
    return 0;
}

void place_on_board(char board[3][3], char x, int y, char symbol) {
    if (toupper(x) == 'A') {
        board[y-1][0] = symbol;
    } else if (toupper(x) == 'B') {
        board[y-1][1] = symbol;
    } else {
        board[y-1][2] = symbol;
    }
}

void ask_user(char board[3][3], bool whose) {
    std::cout << "Enter a coordinate to place an ";
    char x;
    int y, x_actual;
    if (!whose) {
        std::cout << "X, space-separated: ";
        std::cin >> x >> y;
        place_on_board(board, x, y, 'X');
    } else {
        std::cout << "O, space-separated: ";
        std::cin >> x >> y;
        place_on_board(board, x, y, 'O');
    }
}

void show_board(char board[3][3]) {
    std::cout << "\n+-A-+-B-+-C-+\n"\
                 "1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |\n" << \
                 "+---+---+---+\n" << \
                 "2 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |\n" << \
                 "+---+---+---+\n" << \
                 "3 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |\n" << \
                 "+---+---+---+\n" << std::endl;
}

int main() {
    bool turn = false;
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    show_board(board);
    while (1) {
        ask_user(board, turn);
        show_board(board);
        int result = win(board);
        if (result == 1) {
            std::cout << "X wins!" << std::endl;
            break;
        } else if (result == 2) {
            std::cout << "O wins!" << std::endl;
            break;
        } else if (result == 3) {
            std::cout << "Tie!" << std::endl;
            break;
        }
        if (!turn) {
            turn = true;
        } else {
            turn = false;
        }
    }
}