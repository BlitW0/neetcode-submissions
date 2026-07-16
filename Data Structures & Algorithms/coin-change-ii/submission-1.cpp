class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector dp(n + 1, vector <long> (amount + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][0] = 1; // base case, amount 0 vacuously 1
            for (int t = 1; t <= amount; t++) {
                int val = dp[i + 1][t];
                if (coins[i] <= t)
                    val += dp[i][t - coins[i]];
                dp[i][t] = val;
            }
        }

        return dp[0][amount];
    }
};