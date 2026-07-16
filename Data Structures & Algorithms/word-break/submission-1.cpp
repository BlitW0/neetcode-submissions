class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector <int> dp(n + 1);

        dp[0] = 1;
        for (int i = 1; i <= n; i++)
            for (auto& word : wordDict) {
                int w = word.size();
                if (i >= w and s.substr(i - w, w) == word)
                    dp[i] = dp[i] or dp[i - w];
                if (dp[i]) break; // found true, stop
            }
        return dp[n];
    }
};