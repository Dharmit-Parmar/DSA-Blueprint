#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, const vector<string>& board, int n) {
        // checking  up
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i{row - 1}, j{col - 1}; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }

        for (int i{row - 1}, j{col + 1}; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void backtrack(int row, int n, vector<string>& board,
                   vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int i{0}; i < n; i++) {
            if (isSafe(row, i, board, n)) {
                board[row][i] = 'Q';
                backtrack(row + 1, n, board, ans);
                board[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board, ans);
        return ans;
    }
};