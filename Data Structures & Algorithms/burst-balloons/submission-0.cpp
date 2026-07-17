class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector <int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        // assume k will be the xth last balloon to be popped
        // where x = current depth of recursion

        // so if i am inside i..j, k is last, everything else
        // in the range is gone and for coins i take i-1 and j+1
        
        // ex. 3 is 2nd last, [3, 1, 5] is the subproblem
        // 3 is part of if we first take 8 as last
        // so for 3 i-1=1 and j+1=8 -> 1*3*8, 

        int mx = INT_MIN;
        for (int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1];
            mx = max(mx, 
            coins + solve(i, k - 1, nums, dp) + solve(k + 1, j, nums, dp));
        }
        return dp[i][j] = mx;
    }

    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector dp(n, vector <int> (n, -1));
        return solve(1, n - 2, nums, dp);
    }
};