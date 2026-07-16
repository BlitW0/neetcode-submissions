class Solution {
public:
    int uniquePaths(int m, int n) {
        // two possible places you came from
        // dp[i][j] = dp[i - 1][j] (up) + dp[i][j - 1] (left)

        vector <vector <int> > dp(n, vector <int> (m, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (not i or not j) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }

        return dp[n - 1][m - 1];
    }
};