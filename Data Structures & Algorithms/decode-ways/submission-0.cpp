class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector <int> dp(n + 1);

        dp[0] = 1; // assume 1 for empty string
        for (int i = 1; i <= n; i++) {
            char cur = s[i - 1], prev = i > 1 ? s[i - 2] : '\0';
            
            if (cur == '0') {
                // impossible to use 0 as 1 or 2 digit letter
                if (prev != '1' and prev != '2')
                    return 0;
                dp[i] += dp[i - 2];
            } else {
                dp[i] += dp[i - 1];
                // 2 digit letter possible
                if (prev == '1' or (prev == '2' and cur <= '6'))
                    dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};