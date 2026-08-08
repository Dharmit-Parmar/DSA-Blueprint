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
     * @brief Helper function that flattens the subtree and returns its tail
     * (last node).
     * @param root Current root of the subtree.
     * @return TreeNode* The last node of the flattened linked list for this
     * subtree.
     */
    TreeNode* flattenHelper(TreeNode* root) {
        // Base case: if node is null, return null
        if (root == nullptr) {
            return nullptr;
        }

        // If it's a leaf node, it is already its own tail
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }

        // Step 1: Go down the left and right subtrees recursively
        TreeNode* leftTail = flattenHelper(root->left);
        TreeNode* rightTail = flattenHelper(root->right);

        // Step 2: As we return (backtrack), if a left subtree exists,
        // stitch the old right subtree to the end of the left tail,
        // then move the left subtree to the right.
        if (leftTail != nullptr) {
            // Save/attach the old right subtree to the tail of the left
            // flattened list
            leftTail->right = root->right;
            // Move the left subtree over to the right side
            root->right = root->left;
            // Clear the left pointer as required
            root->left = nullptr;
        }

        // Step 3: Return the new tail of this flattened section
        // If there was a right subtree (or old right attached to leftTail), its
        // tail is rightTail. Otherwise, it's leftTail, or just the root itself.
        if (rightTail != nullptr) {
            return rightTail;
        }
        if (leftTail != nullptr) {
            return leftTail;
        }
        return root;
    }

    /**
     * @brief Flattens a binary tree into a linked list in-place (LeetCode 114).
     *
     * METHODOLOGY: Post-order DFS with Tail-Tracking (Left-first return &
     * stitch)
     * 1. Recursively traverse down to the left and right subtrees.
     * 2. On the way back up (backtracking), take the tail of the flattened left
     * subtree, attach the node's original right subtree to it, and shift the
     * left child to the right.
     * 3. Return the updated tail node upward so parent nodes can stitch their
     * own right subtrees.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N), where N is the number of nodes in the tree,
     * since every node is visited once.
     * - Space Complexity: O(H), where H is the height of the tree, for the
     * recursion stack space.
     */
    void flatten(TreeNode* root) { flattenHelper(root); }
};