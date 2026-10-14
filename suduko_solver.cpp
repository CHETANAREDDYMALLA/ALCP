#include <iostream>
#include <vector>
using namespace std;
bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}
bool solveSudoku(vector<vector<int>>& board) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }
    if (!isEmpty) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudoku(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}
void printBoard(const vector<vector<int>>& board) {
    for (int r = 0; r < 9; r++) {
        for (int d = 0; d < 9; d++) {
            cout << board[r][d] << " ";
        }
        cout << endl;
    }
}
int main() {
    vector<vector<int>> board(9, vector<int>(9));
    cout << "Enter the Sudoku board (use 0 for empty cells):" << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    if (solveSudoku(board)) {
        cout << "\nSolved Sudoku Board:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }
    return 0;
}
