class Solution {
public:
    const int OFS = 2000;

    int f(int i, int target, vector<int>& nums, vector <vector <int> >& dp) {
        if (i == nums.size()) {
            if (target == 0) return 1;
            return 0;
        }
        int tidx = target + OFS;
        if (dp[i][tidx] != -1) return dp[i][tidx];

        return dp[i][tidx] = f(i + 1, target - nums[i], nums, dp) + f(i + 1, target + nums[i], nums, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector dp(n, vector <int> (2*OFS + 1, -1));
        return f(0, target, nums, dp);
    }
};