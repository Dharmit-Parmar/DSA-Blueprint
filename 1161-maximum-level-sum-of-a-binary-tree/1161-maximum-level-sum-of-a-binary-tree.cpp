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
    int maxLevelSum(TreeNode* root) {
        // Handle empty tree edge case
        if (!root)
            return -1;

        int maxSum = INT_MIN;
        int anslevel = 1;
        int currentLevel = 1;

        // Queue for level-order traversal (BFS)
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int sum = 0;

            // Process all nodes at the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* n = q.front();
                q.pop();

                sum += n->val;

                // Push child nodes for the next level
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }

            // Update maxSum and record level
            // (Using strict '>' ensures we keep the smallest level number in
            // case of ties)
            if (sum > maxSum) {
                anslevel = currentLevel;
                maxSum = sum;
            }

            currentLevel++;
        }

        return anslevel;
    }
};