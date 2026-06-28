class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size(), ans1 = max(nums[1], nums[0]), ans2 = nums[0];
        int ans = max(ans1, ans2);
        for (int i = 2; i < n; i++) {
            ans = max(ans1, nums[i] + ans2);
            // cout << ans2 << ' ' << ans1 << ' ' << ans << '\n';
            ans2 = ans1, ans1 = ans;
        }
        return ans;
    }
};