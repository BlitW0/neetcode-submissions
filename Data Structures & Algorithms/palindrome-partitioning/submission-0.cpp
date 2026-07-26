class Solution {
public:
    bool is_pal(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    void solve(int idx, string& s, vector <string>& pals, vector <vector <string> >& ans) {
        if (idx == s.size()) {
            ans.push_back(pals);
            return;
        }

        string cur = "";
        for (int i = idx; i < s.size(); i++) {
            cur += s[i];
            if ( is_pal(cur) ) {
                pals.push_back(cur);
                solve(i + 1, s, pals, ans);
                pals.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if (s.empty()) return ans;

        vector <string> pals;
        solve(0, s, pals, ans);
        return ans;
    }
};