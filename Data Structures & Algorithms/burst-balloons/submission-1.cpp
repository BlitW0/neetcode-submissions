class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // assume k will be the xth last balloon to be popped
        // where x = current depth of recursion

        // so if i am inside i..j, k is last, everything else
        // in the range is gone and for coins i take i-1 and j+1
        
        // ex. 3 is 2nd last, [3, 1, 5] is the subproblem
        // 3 is part of if we first take 8 as last
        // so for 3 i-1=1 and j+1=8 -> 1*3*8, 

        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector dp(n + 2, vector <int> (n + 2, 0));

        for (int i = n; i >= 1; i--)
            for (int j = 1; j <= n; j++) {
                if (i > j) continue;

                int mx = INT_MIN;
                for (int k = i; k <= j; k++) {
                    int coins = nums[i - 1] * nums[k] * nums[j + 1];
                    mx = max(mx, 
                    coins + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = mx;
            }

        return dp[1][n];
    }
};