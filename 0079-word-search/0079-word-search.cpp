class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int r, int c) {
        int n = board.size();
        int m = board[0].size();

        if (i == word.size()) {
            return true;
        }
        if (r >= n || c >= m || r < 0 || c < 0 || board[r][c] != word[i]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';
        bool found = dfs(board, word, i + 1, r + 1, c) ||
                     dfs(board, word, i + 1, r - 1, c) ||
                     dfs(board, word, i + 1, r, c + 1) ||
                     dfs(board, word, i + 1, r, c - 1);

        board[r][c] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int r{0}; r < n; r++) {
            for (int c{0}; c < m; c++) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, word, 0, r, c)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};