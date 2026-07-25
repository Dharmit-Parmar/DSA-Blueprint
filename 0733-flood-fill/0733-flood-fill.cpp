class Solution {
public:
    /**
     * @brief Performs a Depth-First Search (DFS) to flood fill connected
     * pixels.
     * @details Recursively checks all 4 directions (up, down, left, right) from
     *          the current pixel. If a neighbor matches the original color,
     *          it updates it to the new color and continues spreading.
     */
    void dfs(vector<vector<int>>& image, int r, int c, int orignal, int color) {
        // Base case: Check boundaries and ensure current pixel matches the
        // original color
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() ||
            image[r][c] != orignal)
            return;

        // Paint the current pixel with the new color
        image[r][c] = color;

        // Recursively visit all 4 adjacent neighbors
        dfs(image, r - 1, c, orignal, color); // Up
        dfs(image, r + 1, c, orignal, color); // Down
        dfs(image, r, c - 1, orignal, color); // Left
        dfs(image, r, c + 1, orignal, color); // Right
    }

    /**
     * @brief Starts the flood fill algorithm on a 2D image.
     *
     * METHODOLOGY: Depth-First Search (DFS)
     * 1. Capture the original color of the starting pixel (sr, sc).
     * 2. Edge case check: If the target color is already the same as the
     * original color, no changes are needed, preventing an infinite recursion
     * loop.
     * 3. Launch DFS from the starting coordinates.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N), where N is the number of pixels in the image.
     *   In the worst case, every pixel is visited once.
     * - Space Complexity: O(N) for the recursive call stack in the worst-case
     * scenario.
     */
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int orignal = image[sr][sc];

        // Only run DFS if the new color is different from the original color,
        // otherwise, it would cause an infinite loop because we wouldn't change
        // the pixel value, and image[r][c] != orignal would never trigger.
        if (orignal != color)
            dfs(image, sr, sc, orignal, color);

        return image;
    }
};