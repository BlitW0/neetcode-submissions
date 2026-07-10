class Solution {
public:
    int rob(vector<int>& nums) {
        // try skipping either first or last, take max of both
        // ans = max(dp[0..n-1], dp[1..n]);
        int n = nums.size();
        if (n < 2) return nums[0];
        if (n < 3) return max(nums[0], nums[1]);

        int dp1[2] = {nums[0], max(nums[0], nums[1])}, cur1;
        int dp2[2] = {nums[1], max(nums[1], nums[2])}, cur2;

        for (int i = 2; i < n; i++) {
            if (i < n - 1) {
                cur1 = max(dp1[1], dp1[0] + nums[i]);
                dp1[0] = dp1[1], dp1[1] = cur1;
            }
            if (i > 2) {
                cur2 = max(dp2[1], dp2[0] + nums[i]);
                dp2[0] = dp2[1], dp2[1] = cur2;
            }
        }

        return max(dp1[1], dp2[1]);
    }
};