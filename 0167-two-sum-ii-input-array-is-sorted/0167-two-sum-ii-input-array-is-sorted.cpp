/**
 * @file TwoSumII.cpp
 * @author Your Name
 * @brief Solution for LeetCode 167: Two Sum II - Input Array Is Sorted (or
 * standard Two Sum variation)
 * @details This implementation uses a Hash Map (unordered_map) approach.
 *          Note: If this is specifically for LeetCode 167 where the input array
 * is already sorted, a Two-Pointer approach achieves O(1) space, but this Hash
 * Map approach is perfectly valid and runs in O(n) time and O(n) space.
 *
 * GitHub: https://github.com/your-username/leetcode-solutions
 */

class Solution {
public:
    /**
     * @brief Finds two numbers such that they add up to a specific target
     * number.
     * @param numbers Vector of integers to search through.
     * @param target The target sum.
     * @return vector<int> 1-based indices of the two numbers.
     *
     * METHODOLOGY: Complement Lookup via Hash Map
     * For every element `numbers[i]`, its required complement to reach the
     * target is `target - numbers[i]`. We check if this complement already
     * exists in our map. If it does, we've found our pair. If it doesn't, we
     * store the current number and its index in the map and keep moving.
     *
     * COMPLEXITY ANALYSIS:
     * - Time Complexity: O(n) -> We traverse the array of size 'n' exactly
     * once. Hash map lookups/insertions take O(1) time on average.
     * - Space Complexity: O(n) -> In the worst-case scenario, we store up to
     * 'n' elements in the map.
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        // Key: Element Value, Value: Its 0-based index in the array
        unordered_map<int, int> m;

        for (int i{0}; i < n; i++) {

            // Calculate what value we need to find to match with numbers[i]
            int current = target - numbers[i];

            // Check if the required complement is already in our map
            if (m.find(current) != m.end()) {
                // Return 1-based indices as per problem requirements (e.g.,
                // LeetCode 167) m[current] is the index of the previously seen
                // complement i is the current index
                return {m[current] + 1, i + 1};
            }

            // Store the current number and its index for future lookups
            // emplace() is slightly more efficient than operator[] as it avoids
            // temporary object creation
            m.emplace(numbers[i], i);
        }

        // Return empty vector if no solution is found
        return {};
    }
};