#include <algorithm>
#include <vector>

class Solution {
public:
    /**
     * @brief Recursive helper function to find all unique combinations that sum
     * to target where each number in candidates may only be used once.
     *
     * @param candidates Array of candidate numbers (must be sorted beforehand).
     * @param s Current path / combination of numbers being explored.
     * @param target Remaining sum required to complete a valid combination.
     * @param index Starting index for candidate selection.
     * @param result Reference to vector storing all unique valid combinations.
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

        // Explore choices starting from 'index'
        for (int i = index; i < candidates.size(); i++) {
            // Duplicate Skipping: If the current element is a duplicate of the
            // previous one within the same tree level, skip it to avoid
            // duplicate combinations.
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Choose: Include the current candidate in the combination
            s.push_back(candidates[i]);

            // Explore: Recurse with the reduced target.
            // Pass 'i + 1' because each element can only be used once in
            // Combination Sum II.
            helper(candidates, s, target - candidates[i], i + 1, result);

            // Un-choose (Backtrack): Remove the candidate before trying the
            // next branch
            s.pop_back();
        }
    }

    /**
     * @brief Main function to solve Combination Sum II (LeetCode 40).
     *
     * METHODOLOGY: Backtracking with Sorting and Duplicate Skipping
     * 1. Sort the candidates array so identical numbers are grouped together.
     * 2. Use a backtracking DFS approach similar to Combination Sum I.
     * 3. Pass `i + 1` in the recursive step to ensure elements are not reused.
     * 4. Skip adjacent duplicate values at the same recursion depth to ensure
     * unique results.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(2^n) in the worst case, where n is the number of
     * candidates.
     * - Space Complexity: O(n) for the recursion stack and temporary
     * combination vector.
     */
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates,
                                                  int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> s;

        // Sorting is mandatory for Combination Sum II to handle duplicate
        // filtering effectively
        std::sort(candidates.begin(), candidates.end());

        // Launch backtracking starting from index 0
        helper(candidates, s, target, 0, result);

        return result;
    }
};