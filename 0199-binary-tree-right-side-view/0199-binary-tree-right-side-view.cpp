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
     * @brief Recursive DFS helper to explore the tree visiting the right side
     * first.
     * @param root Current binary tree node being visited.
     * @param level Current depth/level index (i) tracking the height.
     * @param result Vector storing the first encountered node value for each
     * level.
     */
    void dfs(TreeNode* root, int level, vector<int>& result) {
        if (root == nullptr) {
            return;
        }

        // If the current level hasn't been added to our result yet,
        // add it. Because we visit the right subtree first, this
        // is guaranteed to be the rightmost visible node for this level.
        if (level == result.size()) {
            result.push_back(root->val);
        }

        // Step 1: Traverse the right subtree first
        dfs(root->right, level + 1, result);

        // Step 2: Traverse the left subtree second (if the right side
        // already populated this level, left side nodes will be skipped)
        dfs(root->left, level + 1, result);
    }

    /**
     * @brief Returns the values of the nodes visible from the right side
     * ordered from top to bottom (LeetCode 199).
     *
     * METHODOLOGY: Right-First Pre-order DFS with Level Tracking
     * 1. Traverse the tree using a helper function that prioritizes the **right
     * child** before the **left child**.
     * 2. Track the depth level (`level`). The first time we reach any given
     * level, we add that node's value to our result.
     * 3. Because we go right-first, the rightmost node at any given level will
     * always be encountered and recorded first.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N), where N is the number of nodes in the tree,
     * because every node is visited once.
     * - Space Complexity: O(H), where H is the height of the tree, for the
     * recursion call stack and result storage.
     */
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
};