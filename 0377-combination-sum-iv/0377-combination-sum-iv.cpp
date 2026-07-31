class Solution {
public:
    int helper(vector<int>& nums, int target, vector<int>& memo) {
        // TODO 1: Handle base cases
        // - What should you return if target == 0? (Valid sum found)
        if (target == 0)
            return 1;
        // - What should you return if target < 0? (Invalid sum)
        if (target < 0)
            return 0;

        // TODO 2: Check memoization table
        // - If memo[target] is already computed (e.g., not -1), return it
        // immediately
        if (memo[target] != -1) {
            return memo[target];
        }

        int count = 0;

        // TODO 3: Iterate through all numbers in 'nums'
        // - Since order matters, start your loop from index 0 every time
        // - Recursively call helper for (target - nums[i])
        // - Add the returned result to 'count'
        for (int i = 0; i < nums.size(); i++) {
            count += helper(nums, target - nums[i], memo);
        }

        // TODO 4: Store 'count' in memo[target] and return it
        return memo[target] = count;
    }

    int combinationSum4(vector<int>& nums, int target) {
        // Initialize memoization array with -1 (unvisited states)
        // Size is target + 1 to cover values from 0 to target
        vector<int> memo(target + 1, -1);

        return helper(nums, target, memo);
    }
};