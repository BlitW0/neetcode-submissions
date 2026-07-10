class Solution {
public:
    int rob(vector<int>& nums) {
        // rob current house or don't
        // if rob, can't rob prev house
        // if don't, see how much max you could get till prev house
        // dp[i] = max(dp[i - 1], nums[i] + dp[i - 2])

        int n = nums.size(), dp[2] = {nums[0]};
        if (n < 2) return dp[0];

        dp[1] = max(dp[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int temp = max(dp[1], nums[i] + dp[0]);
            dp[0] = dp[1], dp[1] = temp;
        }
        return dp[1];
    }
};