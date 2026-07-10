class Solution {
public:
    string longestPalindrome(string s) {
        int mxlen = -1, st = -1, n = s.length();

        // dp[i][j] true if s[i..j] is palindrome
        vector <vector <bool> > dp(n, vector <bool> (n, 0));
        
        // fill table in increasing length, for each starting pos i
        for (int len = 1; len <= n; len++) {
            int idx = -1;
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                // ends of substr are eq
                // if len <= 2, pal of len 1 or 2
                // else check substr[i+1..j-1] (middle) of substr 
                if (s[i] == s[j])
                    dp[i][j] = (len <= 2 or dp[i + 1][j - 1]);
                // update start idx if s[i..j] is pal
                idx = (dp[i][j] ? i : idx);
            }
            if (idx != -1) st = idx, mxlen = len;
        }

        return s.substr(st, mxlen);
    }
};