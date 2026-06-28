class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // Knapsack problem
        // Efficient implementation with 1-d DP
        // Kind of like coin change, we will DP array in reverse

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum & 1)
            return false;
        
        const int MAX = sum / 2;
        vector <bool> dp(MAX + 1);

        dp[0] = true;
        for (int num : nums)
            for (int sumpos = MAX; sumpos >= num; sumpos--)
                dp[sumpos] = dp[sumpos] || dp[sumpos - num];

        return dp[sum / 2];
    }
};