class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector dp(n + 2, vector <int> (2 + 1, 0));

        for (int i = n - 1; i >= 0; i--)
            for (int h = 1; h >= 0; h--) {
                int val = h ? prices[i] : -prices[i];
                // if i'm holding, i skip one index after selling
                // flip hold if i choose to either buy or sell
                dp[i][h] = max(dp[i + 1][h], val + dp[i + 1 + h][1 - h]);
            }

        return dp[0][0];
    }
};