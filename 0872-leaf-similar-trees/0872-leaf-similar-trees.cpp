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
    void dfs(TreeNode* root, vector<int>& s) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            s.push_back(root->val);
            return;
        }
        dfs(root->left, s);
        dfs(root->right, s);

        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1;
        vector<int> seq2;
        dfs(root1, seq1);
        dfs(root2, seq2);

        return seq1 == seq2;
    }
};