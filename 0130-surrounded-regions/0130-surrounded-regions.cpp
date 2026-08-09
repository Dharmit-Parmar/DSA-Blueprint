class Solution {
public:
    /**
     * @brief Depth-First Search helper to mark all connected 'O' cells
     * reachable from the border.
     * @param board The 2D grid matrix.
     * @param row Current row index.
     * @param col Current column index.
     * @param visited 2D boolean grid tracking visited cells.
     */
    void dfs(vector<vector<char>>& board, int row, int col,
             vector<vector<bool>>& visited) {
        int n = board.size();
        int m = board[0].size();

        if (row >= n || col >= m || row < 0 || col < 0)
            return;

        if (board[row][col] == 'O' && !visited[row][col]) {
            visited[row][col] = true;
            dfs(board, row + 1, col, visited);
            dfs(board, row - 1, col, visited);
            dfs(board, row, col + 1, visited);
            dfs(board, row, col - 1, visited);
        }
    }

    /**
     * @brief Solves Surrounded Regions (LeetCode 130).
     *
     * METHODOLOGY: Border-First DFS Marking
     * 1. Any 'O' connected to the border cannot be surrounded, so it must be
     * preserved.
     * 2. Traverse DFS starting from all 'O's on the top, bottom, left, and
     * right borders and mark them as visited.
     * 3. Iterate through the entire board: any 'O' that remains unvisited is
     * completely surrounded by 'X's and gets flipped to 'X'.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N * M), where N is rows and M is columns. Every cell
     * is visited at most once.
     * - Space Complexity: O(N * M) for the visited grid and the recursion call
     * stack.
     */
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return;

        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // 1. Check top (row 0) and bottom (row n - 1) boundaries across all
        // columns
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !visited[0][j]) {
                dfs(board, 0, j, visited);
            }
            if (board[n - 1][j] == 'O' &&
                !visited[n - 1][j]) { // Fixed: used n - 1 instead of m - 1
                dfs(board, n - 1, j, visited);
            }
        }

        // 2. Check left (col 0) and right (col m - 1) boundaries across all
        // rows
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(board, i, 0, visited);
            }
            if (board[i][m - 1] == 'O' &&
                !visited[i][m - 1]) { // Fixed: used m - 1 instead of n - 1
                dfs(board, i, m - 1, visited);
            }
        }

        // 3. Flip all unvisited 'O's to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};