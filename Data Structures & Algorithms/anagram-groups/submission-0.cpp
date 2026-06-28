class Solution {
public:
    string get_hash(vector <int> cnt) {
        string val = "";
        for (int i = 0; i < 26; i++) {
            val += char(int('a') + i);
            val += to_string(cnt[i]);
        }
        return val;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > mp;
        for (string s : strs) {
            vector <int> cnt(26, 0);
            for (char c : s)
                for (int i = 0; i < 26; i++)
                    cnt[c - 'a']++;
            mp[get_hash(cnt)].push_back(s); 
        }
        vector<vector <string> > ans;
        for (auto p : mp)
            ans.push_back(p.second);
        return ans;
    }
};
