class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int dp[2] = {cost[0], cost[1]};
        for (int i = 2; i < n; i++) {
            // dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
            int temp = cost[i] + min(dp[0], dp[1]);
            dp[0] = dp[1], dp[1] = temp;
        }
        return min(dp[0], dp[1]);
    }
};