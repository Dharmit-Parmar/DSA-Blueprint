class Solution {
public:
    /**
     * @brief Recursive helper function to find all unique combinations that sum
     * to target.
     *
     * @param candidates Array of candidate numbers.
     * @param s Current path / combination of numbers being explored.
     * @param target Remaining sum required to complete a valid combination.
     * @param index Starting index for candidate selection (prevents duplicate
     * combinations).
     * @param result Reference to vector storing all valid combinations.
     */
    void helper(vector<int>& candidates, vector<int>& s, int target, int index,
                vector<vector<int>>& result) {

        // Base case 1: Found a valid combination (remaining target is 0)
        if (target == 0) {
            result.push_back(s); // Store the current valid combination
            return;
        }

        // Base case 2: Exceeded the target sum (prune this search branch)
        if (target < 0) {
            return;
        }

        // Explore choices starting from 'index' to avoid duplicate permutations
        for (int i = index; i < candidates.size(); i++) {
            // Choose: Include the current candidate in the combination
            s.push_back(candidates[i]);

            // Explore: Recurse with the reduced target.
            // Pass 'i' (not 'i + 1') to allow reusing the same candidate number
            // infinitely.
            helper(candidates, s, target - candidates[i], i, result);

            // Un-choose (Backtrack): Remove the candidate before trying the
            // next branch
            s.pop_back();
        }
    }

    /**
     * @brief Main function to solve Combination Sum (LeetCode 39).
     *
     * METHODOLOGY: Backtracking (Depth-First Search)
     * We explore a decision tree where at each step we choose to include a
     * candidate and subtract its value from the remaining target.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(2^T) where T is target / min_candidate_value. In the
     * worst case, the tree depth can reach T.
     * - Space Complexity: O(T) for the recursion stack and intermediate
     * combination path 's'.
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> s;

        // Launch backtracking starting from index 0
        helper(candidates, s, target, 0, result);

        return result;
    }
};