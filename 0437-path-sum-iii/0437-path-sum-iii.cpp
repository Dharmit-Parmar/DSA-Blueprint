
class Solution {
public:
    void dfs(TreeNode* root, int t, long long sum,
             unordered_map<long long, int>& h, int& c) {
        if (!root)
            return;

        sum += root->val;

        long long val = sum - t;
        if (h.count(val)) {
            c += h[val];
        }

        h[sum]++;

        dfs(root->left, t, sum, h, c);
        dfs(root->right, t, sum, h, c);

        h[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        int c{0};
        unordered_map<long long, int> h;

        h[0] = 1;

        dfs(root, targetSum, 0, h, c);

        return c;
    }
};