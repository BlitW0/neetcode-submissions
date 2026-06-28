class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector <string> > ans;
        for (string s : strs) {
            string hash = "";
            int cnt[26] = {0};

            for (char c : s)
                cnt[c - 'a']++;
            hash = to_string(cnt[0]);
            for (int i = 1; i < 26; i++)
                hash += "," + to_string(cnt[i]);
            
            ans[hash].push_back(s);
        }

        vector <vector <string> > ret;
        for (auto p : ans)
            ret.push_back(p.second);
        return ret;
    }
};
