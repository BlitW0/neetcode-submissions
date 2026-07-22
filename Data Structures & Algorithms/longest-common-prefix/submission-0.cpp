class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        
        int end = -1;
        for (int i = 0; i < strs[0].size(); i++) {
            bool all = true;
            for (string word : strs)
                if (strs[0][i] != word[i]) {
                    all = false;
                    break;
                }
            if (not all) break;
            end = i;
        }

        return strs[0].substr(0, end + 1);
    }
};