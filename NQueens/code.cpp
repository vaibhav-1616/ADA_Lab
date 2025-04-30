#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<vector<int>> &board, int row, int col, int n) {
    // Check same column
    for (int i = 0; i < row; i++)
        if (board[i][col]) return false;

    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j]) return false;

    return true;
}

bool solve(vector<vector<int>> &board, int row, int n) {
    if (row == n) return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;
            if (solve(board, row + 1, n))
                return true;
            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    int n = 8; // You can change this to any N
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solve(board, 0, n)) {
        cout << "N-Queens Solution:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << (board[i][j] ? "Q " : ". ");
            cout << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
