class Solution {
public:
    /**
     * @brief Recursive Depth-First Search helper to find the minimum depth of a
     * binary tree.
     * @param root Current node being visited.
     * @param cnt Reference to the minimum depth tracker.
     * @param traceCount Current depth count from the root to the current node.
     */
    void dfs(TreeNode* root, int& cnt, int traceCount) {
        if (root == nullptr) {
            return;
        }

        // If it's a leaf node, check and update the minimum depth
        if (root->left == nullptr && root->right == nullptr) {
            cnt = min(cnt, traceCount);
            return;
        }

        // Traverse left (pass traceCount + 1 by value so it doesn't mess up the
        // right branch)
        if (root->left != nullptr) {
            dfs(root->left, cnt, traceCount + 1);
        }

        // Traverse right
        if (root->right != nullptr) {
            dfs(root->right, cnt, traceCount + 1);
        }
    }

    /**
     * @brief Finds the minimum depth of a binary tree (LeetCode 111).
     *
     * METHODOLOGY: Depth-First Search (DFS) with Pre-order Traversal
     * 1. Use a helper function to traverse the tree while tracking the depth
     * (`traceCount`).
     * 2. When a leaf node (both left and right children are null) is reached,
     *    update the global minimum depth (`cnt`).
     * 3. Pass `traceCount` by value so that backtracking happens naturally when
     *    returning from recursion branches.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N), where N is the number of nodes in the binary
     * tree, as every node is visited once.
     * - Space Complexity: O(H), where H is the height of the tree, representing
     * the maximum call stack depth.
     */
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int cnt = INT_MAX;
        // Start traversal with root depth as 1
        dfs(root, cnt, 1);

        return cnt;
    }
};