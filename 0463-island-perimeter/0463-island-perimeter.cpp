class Solution {
public:
    /**
     * @brief Depth-First Search helper to calculate the perimeter of an island.
     * @param grid The 2D map matrix (modified in-place to track visited cells
     * using -1).
     * @param row Current row index.
     * @param col Current column index.
     * @return int Contribution to the perimeter from the current cell and its
     * paths.
     */
    int dfs(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();

        // Fixed: changed '>' to '>=' to prevent out-of-bounds segmentation
        // faults
        if (row >= n || col >= m || row < 0 || col < 0) {
            return 1;
        }

        if (grid[row][col] == 0)
            return 1;

        if (grid[row][col] == -1)
            return 0;

        int p{0};
        grid[row][col] = -1;
        p += dfs(grid, row + 1, col);
        p += dfs(grid, row - 1, col);
        p += dfs(grid, row, col + 1);
        p += dfs(grid, row, col - 1);

        return p;
    }

    /**
     * @brief Calculates the perimeter of the island (LeetCode 463).
     *
     * METHODOLOGY: In-place DFS Traversal
     * 1. Scan the grid to locate the first piece of land (`1`).
     * 2. Traverse the island using DFS, marking visited land cells as `-1`
     * in-place.
     * 3. Whenever a recursive call hits water (`0`) or goes out of bounds, it
     * means we found an exposed edge, so we add `1` to the perimeter count.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N * M), where N is the number of rows and M is the
     * number of columns. Every cell in the island is visited once.
     * - Space Complexity: O(N * M) in the worst case for the recursion call
     * stack if the island spans the entire grid.
     */
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i{0}; i < n; i++) {
            for (int j{0}; j < m; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }

        return 0;
    }
};