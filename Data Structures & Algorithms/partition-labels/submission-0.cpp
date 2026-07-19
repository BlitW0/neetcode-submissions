class Solution {
public:
    vector<int> partitionLabels(string s) {
        int lastpos[26], n = s.size();
        for (int i = 0; i < n; i++)
            lastpos[s[i] - 'a'] = i;
        
        int st = 0, en = 0;
        vector <int> ans;
        for (int i = 0; i < n; i++) {
            // everytime adding char, push end to its last pos
            // so substring can't finish until that pos
            en = max(en, lastpos[ s[i] - 'a' ]);

            if (i == en) {
                ans.push_back(en - st + 1);
                st = i + 1;
            }
        }
        return ans;
    }
};