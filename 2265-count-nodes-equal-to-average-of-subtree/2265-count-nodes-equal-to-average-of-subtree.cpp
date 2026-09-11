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
    // {sum , num of node}
    pair<int, int> dfs(TreeNode* root, int& c) {
        if (!root)
            return {0, 0};

        pair<int, int> left = dfs(root->left, c);
        pair<int, int> right = dfs(root->right, c);

        if ((left.first + right.first + root->val) /
                (left.second + right.second + 1) ==
            root->val)
            c++;

        return {(root->val + left.first + right.first),
                (1 + left.second + right.second)};
    }
    int averageOfSubtree(TreeNode* root) {

        int count{0};
        dfs(root, count);
        return count;
    }
};