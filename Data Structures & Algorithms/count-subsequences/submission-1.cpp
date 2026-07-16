class Solution {
public:
    int numDistinct(string s, string t) {
        // s is coins
        // t is target
        // knapsack where every char from s can be used only once

        int n = t.size();
        vector <unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (char c : s)
            for (int i = n - 1; i >= 0; i--)
                if (c == t[i])
                    dp[i + 1] += dp[i];
        
        return dp[n];
    }
};