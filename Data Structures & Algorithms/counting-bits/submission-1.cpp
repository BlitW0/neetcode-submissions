class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> dp(n + 1, 0);
        if (n == 0)
            return dp;

        dp[1] = 1;
        int offs = 1;

        for (int i = 2; i <= n; i++) {
            if ((i & (i - 1)) == 0)
                offs <<= 1;
            
            dp[i] = dp[i - offs] + 1;
        }

        return dp;
    }
};
