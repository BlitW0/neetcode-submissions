class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Logic
        // If text1[i] = text2[j], we can use that character to make lcs
        // If not, we can either discard text1[i] or text2[j] and see
        // which one gives better answer

        int n = text1.length(), m = text2.length();
        vector <vector <int> > lcs(n + 1, vector <int> (m + 1 , 0));

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1])
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                else
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }

        return lcs[n][m];
    }
};