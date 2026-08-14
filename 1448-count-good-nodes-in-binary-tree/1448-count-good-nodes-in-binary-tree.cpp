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
     * @brief Recursive DFS helper to count good nodes along root-to-leaf paths.
     * @param root Current binary tree node being visited.
     * @param maxNode The maximum value encountered so far along the current
     * path.
     * @param count Reference to the running count of good nodes.
     */
    void dfs(TreeNode* root, int maxNode, int& count) {
        if (!root)
            return;

        // If the current node's value is greater than or equal to the maximum
        // seen so far on this path, it is a "good" node.
        if (root->val >= maxNode) {
            count++;
            maxNode =
                root->val; // Update max for subsequent nodes down this path
        }

        // Recurse down both subtrees
        dfs(root->left, maxNode, count);
        dfs(root->right, maxNode, count);
    }

    /**
     * @brief Counts the number of "good" nodes in a binary tree (LeetCode
     * 1448).
     *
     * METHODOLOGY: Pre-order DFS with Path-Max Tracking
     * 1. Traverse the tree recursively while tracking the maximum node value
     * (`maxNode`) encountered from the root down to the current node.
     * 2. A node is defined as "good" if no node in its path from the root has a
     * value greater than it.
     * 3. Because `maxNode` is passed by value, changes made down one branch do
     * not affect sibling or parent branches, ensuring path isolation.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N), where N is the number of nodes in the tree,
     * since every node is visited once.
     * - Space Complexity: O(H), where H is the height of the tree, required for
     * the recursion call stack.
     */
    int goodNodes(TreeNode* root) {
        int c{0};
        int maxNode = INT_MIN; // Safe initialization for negative node values

        dfs(root, maxNode, c);

        return c;
    }
};