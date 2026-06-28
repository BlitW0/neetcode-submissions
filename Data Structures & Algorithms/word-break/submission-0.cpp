class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Exactly like coin change dp.
        // The only difference is that amount is a string 
        // and denominations are words.

        int slen = s.length();
        vector <bool> dp(slen + 1, 0);
        dp[0] = true;

        for (int i = 1; i <= slen; i++)
            for (string word: wordDict) {
                int w = word.length();
                if (i >= w && s.substr(i - w, w) == word) {
                    dp[i] = dp[i] || dp[i - w];
                }
            }
        
        return dp[slen];
    }
};