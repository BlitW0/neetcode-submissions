class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector <vector <int> >& dp) {
        if (i == t.size()) return dp[i][j] = 1;
        if (j == s.size()) return dp[i][j] = 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ret = 0;
        if (t[i] == s[j])
            ret = solve(i + 1, j + 1, s, t, dp);
        ret += solve(i, j + 1, s, t, dp);
        return dp[i][j] = ret;
    }

    int numDistinct(string s, string t) {
        int n = t.size(), m = s.size();
        vector dp(n + 1, vector <int> (m + 1, -1));
        return solve(0, 0, s, t, dp);
    }
};