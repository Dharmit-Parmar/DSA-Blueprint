class Solution {
public:
    /**
     * @brief Depth-First Search to explore all connected land ('1') cells in 4
     * directions.
     * @param r Current row coordinate.
     * @param c Current column coordinate.
     * @param grid The 2D map of land and water.
     * @param visited 2D boolean grid to track visited cells.
     */
    void dfs(int r, int c, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Base case: Out of bounds, currently on water ('0'), or already
        // visited
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0' ||
            visited[r][c]) {
            return;
        }

        // Mark the current land cell as visited
        visited[r][c] = true;

        // Recursively visit all 4 adjacent neighbors (down, up, right, left)
        dfs(r + 1, c, grid, visited);
        dfs(r - 1, c, grid, visited);
        dfs(r, c + 1, grid, visited);
        dfs(r, c - 1, grid, visited);
    }

    /**
     * @brief Solves Number of Islands (LeetCode 200).
     *
     * METHODOLOGY: 2D Grid Graph Traversal (DFS)
     * 1. Treat each cell `(r, c)` in the 2D matrix as a node in a graph.
     * 2. Iterate through every cell in the grid using nested loops.
     * 3. When an unvisited land cell (`'1'`) is found, it marks the start of a
     * new island. Increment the island count and trigger a DFS to sink/mark all
     * connected land cells.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(M * N), where M is the number of rows and N is the
     * number of columns. Every cell is visited once.
     * - Space Complexity: O(M * N) for the 2D visited array and the recursion
     * call stack in the worst case.
     */
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;

        // Scan every cell in the 2D grid
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // If we encounter unvisited land, we found a new island
                if (grid[r][c] == '1' && !visited[r][c]) {
                    count++;
                    dfs(r, c, grid, visited);
                }
            }
        }

        return count;
    }
};