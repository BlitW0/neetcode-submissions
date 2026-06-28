class Solution {
public:
    int uniquePaths(int m, int n) {
        // If robot is in cell (i, j)
        // It would have come from either (i - 1, j) or (i, j - 1)
        // So we just add the answers of those cells to get answer of (i, j)

        vector <vector <int> > dp(m, vector <int> (n, 0));

        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) {
                if (!i && !j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? dp[i][j - 1] : 0);
            }
        
        return dp[m - 1][n - 1];
    }
};