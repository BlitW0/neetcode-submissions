class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // if c1 == c2 use it, dp[i][j] = 1 + dp[i - 1][j - 1]
        // else
        //      dp[i][j] = max((skip c1) dp[i][j - 1] + (skip c2) dp[i - 1][j])

        int n = text1.size(), m = text2.size();
        // space optimization only use 2 rows of length m
        // for i use even or odd to fetch values
        vector <vector <int> > dp(2, vector <int> (m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i & 1][j] = 1 + dp[(i - 1) & 1][j - 1];
                else 
                    dp[i & 1][j] = max(dp[i & 1][j - 1], dp[(i - 1) & 1][j]);
            }
        return dp[n & 1][m];
    }
};