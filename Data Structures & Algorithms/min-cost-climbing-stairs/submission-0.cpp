class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int ans1 = 0, ans2 = 0, ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = min(ans1 + cost[i - 1], ans2 + cost[i - 2]);
            ans2 = ans1, ans1 = ans;
            // dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return ans;
    }
};