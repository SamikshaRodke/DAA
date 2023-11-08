#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check the left side of the current row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower-left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(std::vector<std::vector<int>>& board, int col, int n) {
    if (col == n) {
        // All queens are placed, and the board is solved
        return true;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1, n)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

void printSolution(const std::vector<std::vector<int>>& board) {
    for (const auto& row : board) {
        for (int col : row) {
            cout << (col == 1 ? "Q " : ". ");
        }
        cout << std::endl;
    }
}

void nQueensWithFirstQueenPlaced(int n, int firstQueenRow, int firstQueenCol) {
    if (n < 4) {
        cout << "No solution exists for N less than 4." << std::endl;
        return;
    }

    vector<vector<int>> board(n, vector<int>(n, 0));
    board[firstQueenRow][firstQueenCol] = 1;

    if (solveNQueens(board, firstQueenCol + 1, n)) {
        printSolution(board);
    } else {
        std::cout << "No solution exists." << std::endl;
    }
}

int main() {
    int n;
    cout<<"enter the number of queens : ";
    cin>>n; // Change this to your desired board size
    int firstQueenRow = 0; // Row where the first queen is placed (0-based index)
    int firstQueenCol = 0; // Column where the first queen is placed (0-based index)
    nQueensWithFirstQueenPlaced(n, firstQueenRow, firstQueenCol);

    return 0;
}
