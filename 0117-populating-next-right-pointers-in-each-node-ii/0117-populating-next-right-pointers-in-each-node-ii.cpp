/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
private:
    /**
     * @brief Helper function using Breadth-First Search (BFS) to connect nodes
     * at each level.
     * @param root Current root of the tree.
     */
    void bfs(Node* root) {
        if (root == nullptr)
            return;

        std::queue<Node*> q;
        q.push(root);

        // Traverse level by level
        while (!q.empty()) {
            int level = q.size();
            Node* prev = nullptr;

            for (int i = 0; i < level; i++) {
                Node* cur = q.front();
                q.pop();

                // Connect the previous node in this level to the current node
                if (prev != nullptr) {
                    prev->next = cur;
                }

                prev = cur;

                // Push children into the queue for the next level
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
    }

public:
    /**
     * @brief Populates each next pointer to point to its next right node
     * (LeetCode 116 / 117).
     *
     * METHODOLOGY: Breadth-First Search (Level-Order Traversal)
     * 1. Use a queue to process the binary tree level by level.
     * 2. For each level, track the nodes sequentially and point each node's
     * `next` pointer to the succeeding node in the queue.
     * 3. The last node of each level naturally keeps its default `nullptr` next
     * pointer.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(N), where N is the total number of nodes in the
     * tree, as every node is visited once.
     * - Space Complexity: O(W), where W is the maximum width of the tree (which
     * can be up to N/2 for a full binary tree), required to store nodes in the
     * BFS queue.
     */
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }

        bfs(root);

        return root;
    }
};