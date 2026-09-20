class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // now doing with the dp
        int n = coins.size();
        const int inf = 1e9;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, inf));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }

        // take the coin first
        for (int i = 1; i <= n; i++) {
            int c = coins[i - 1];

            // now we loop through the target
            for (int j = 1; j <= amount; j++) {
                // we exclude
                int e = dp[i - 1][j];

                // then we include

                int in = inf;
                if (j >= c) {
                    if (dp[i][j - c] != inf) {
                        in = 1 + dp[i][j - c];
                    }
                }

                dp[i][j] = min(e, in);
            }
        }
        return (dp[n][amount] == inf) ? -1 : dp[n][amount];
    }
};