/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    /**
     * @brief Helper function to compute subtree height and check balance
     * simultaneously.
     * @param root Current binary tree node being visited.
     * @return int Height of the subtree if balanced, or -1 if unbalanced.
     */
    int dfs(TreeNode* root) {
        // Base case: An empty node has a height of 0
        if (root == nullptr)
            return 0;

        // Check left subtree height
        int lh = dfs(root->left);
        if (lh == -1)
            return -1;

        // Check right subtree height
        int rh = dfs(root->right);
        if (rh == -1)
            return -1;

        // If the height difference between left and right exceeds 1, mark as
        // unbalanced (-1)
        if (abs(lh - rh) > 1)
            return -1;

        // Return the actual height of the current subtree (1 + max height of
        // children)
        return 1 + max(lh, rh);
    }

    /**
     * @brief Determines if a binary tree is height-balanced (LeetCode 110).
     *
     * METHODOLOGY: Bottom-Up Post-order DFS with Height Propagation
     * 1. Recursively traverse down to the leaves and compute subtree heights
     * from the bottom up.
     * 2. Use `-1` as a sentinel value to signal an unbalanced subtree for early
     * exit.
     * 3. If any node's left and right subtree heights differ by more than 1,
     * return `-1`.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N), where N is the number of nodes in the tree,
     * since every node is visited once.
     * - Space Complexity: O(H), where H is the height of the tree, for the
     * recursion call stack.
     */
    bool isBalanced(TreeNode* root) { return dfs(root) != -1; }
};