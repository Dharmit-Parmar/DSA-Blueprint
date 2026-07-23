class Solution {
public:
    /**
     * @brief Finds the fewest number of coins needed to make up that amount.
     *
     * METHODOLOGY: Bottom-Up Dynamic Programming
     * We create a dp table where dp[i] represents the minimum coins needed for
     * amount i. For each amount from 1 to 'amount', we check every coin to see
     * if it can form a sub-problem solution.
     *
     * COMPLEXITY:
     * - Time Complexity: O(amount * n), where n is the number of coins.
     * - Space Complexity: O(amount) for the dp vector.
     */
    int coinChange(vector<int>& coins, int amount) {
        // Initialize dp array with a value representing infinity (amount + 1 is
        // safe) Size is amount + 1 to account for index 0 up to 'amount'
        vector<int> dp(amount + 1, amount + 1);

        // Base case: 0 coins are needed to make an amount of 0
        dp[0] = 0;

        // Iterate through every amount from 1 to target amount
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                // If the coin can be used for the current amount
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[amount] is still amount + 1, it means the amount cannot be
        // formed
        return dp[amount] > amount ? -1 : dp[amount];
    }
};