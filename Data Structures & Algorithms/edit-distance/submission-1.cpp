class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector dp(n + 1, vector <int> (m + 1, 0));

        dp[0][0] = 0; // both empty
        for (int i = 1; i <= n; i++) // word2 empty
            dp[i][0] = i;
        for (int j = 1; j <= m; j++) // word1 empty
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                dp[i][j] = min({
                    dp[i - 1][j] + 1, // insert at i
                    dp[i][j - 1] + 1, // delete at i, match with word2[0..j-1]
                    dp[i - 1][j - 1] + (word1[i - 1] != word2[j - 1])
                });
            }
        
        return dp[n][m];
    }
};
