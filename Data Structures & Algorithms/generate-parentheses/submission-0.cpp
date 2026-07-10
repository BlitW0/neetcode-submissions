class Solution {
public:
    
    void dfs(int open, int close, vector <string> &ans, string s) {
        if (not open and not close) {
            ans.push_back(s);
            return;
        }
        // can add open by default
        if (open)
            dfs(open - 1, close, ans, s + '(');
        // try close if any left and more than open
        // this means some opens are unbalanced
        if (close and close > open)
            dfs(open, close - 1, ans, s + ')');
    }

    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        dfs(n, n, ans, "");
        return ans;
    }
};