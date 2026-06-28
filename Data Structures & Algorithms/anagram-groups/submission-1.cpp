class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector <string> > ans;
        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());

            if (ans.find(tmp) != ans.end()) {
                ans[tmp].push_back(s);
            } else {
                ans[tmp] = {s};
            }
        }

        vector <vector <string> > ret;
        for (auto p : ans)
            ret.push_back(p.second);
        return ret;
    }
};
