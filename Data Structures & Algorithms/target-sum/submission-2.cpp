class Solution {
public:
    int dp[4001][25];
    const int ofs = 2000;

    int findTargetSumWays(vector<int>& nums, int target) {
        fill_n(dp[0], 4001*25, -1);
        dp[ofs][0] = 1;
        return solve(nums, target, 0);
    }

    int solve(vector<int>& nums, int target, int i = 0) {
        int n = nums.size();
        if (dp[target + ofs][i + 1] != -1)
            return dp[target + ofs][i + 1];
        if (i == n)
            return dp[target + ofs][i + 1] = (target == 0);
        
        dp[target + ofs][i + 1] = solve(nums, target - nums[i], i + 1);
        return dp[target + ofs][i + 1] += solve(nums, target + nums[i], i + 1);
    }
};