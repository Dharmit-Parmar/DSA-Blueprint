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
     * @brief Recursive DFS helper to explore root-to-leaf paths and find those
     * matching targetSum.
     * @param root Current binary tree node being visited.
     * @param target Remaining target sum needed.
     * @param result Reference to the collection of all valid paths.
     * @param s Current path vector.
     */
    void dfs(TreeNode* root, int target, vector<vector<int>>& result,
             vector<int>& s) {
        if (root == nullptr)
            return;

        // Add current node to the path
        s.push_back(root->val);

        // If it's a leaf node and the remaining sum matches, save the path
        if (!root->left && !root->right && target - root->val == 0) {
            result.push_back(s);
        }

        int val = target - root->val;

        // Recurse left if child exists
        if (root->left != nullptr) {
            dfs(root->left, val, result, s);
        }

        // Recurse right if child exists
        if (root->right != nullptr) {
            dfs(root->right, val, result, s);
        }

        // Backtrack: remove current node from path before returning to parent
        s.pop_back();
    }

    /**
     * @brief Finds all root-to-leaf paths where the sum of node values equals
     * targetSum (LeetCode 113).
     *
     * METHODOLOGY: Depth-First Search (DFS) with Backtracking
     * 1. Traverse the binary tree recursively while tracking the running path
     * (`s`) and reducing the target sum by the current node's value.
     * 2. If a leaf node is reached and the remaining target matches the node's
     * value, add the current path to the result collection.
     * 3. Backtrack properly by popping the current node from the path vector
     * before returning.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N^2) in the worst case (where N is the number of
     * nodes), due to copying valid paths into the result vector.
     * - Space Complexity: O(N) for the recursion call stack and temporary path
     * storage.
     */
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> s;

        dfs(root, targetSum, result, s);

        return result;
    }
};