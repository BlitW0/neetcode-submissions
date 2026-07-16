class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // knapsack with target sum(nums)/2
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;

        int target = sum >> 1, n = nums.size();
        vector <int> dp(target + 1);
        dp[0] = true; // pick no elements

        // can pick element only once
        // choose one as last picked in subset
        // and fill dp array backward to avoid reuse
        for (int i = 0; i < n; i++)
            for (int s = target; s >= nums[i]; s--)
                dp[s] = dp[s] or dp[s - nums[i]];

        return dp[target];
    }
};