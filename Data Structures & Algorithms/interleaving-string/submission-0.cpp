class Solution {
public:
    // s1 included till i, s2 till j
    // s3[k] should equal either s1[i] or s2[j]
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if (n + m != s3.size()) return false;
        vector dp(n + 1, vector <bool> (m + 1, false));

        dp[n][m] = true;
        for (int i = n; i >= 0; i--)
            for (int j = m; j >= 0; j--) {
                if (i == n and j == m) continue;

                int k = i + j;
                bool val = false;
                if (i < n and s1[i] == s3[k])
                    val = val or dp[i + 1][j];
                if (j < m and s2[j] == s3[k])
                    val = val or dp[i][j + 1];
                dp[i][j] = val;
            }
        return dp[0][0];
    }
};