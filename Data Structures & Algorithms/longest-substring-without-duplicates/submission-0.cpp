class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, ans = 0, len = s.length();
        unordered_map <char, int> pos;

        while (end < len) {
            int c = s[end];
            // found duplicate, move start pointer
            if (start < end && pos.find(c) != pos.end()) {
                ans = max(ans, end - start);
                pos.erase(s[start++]);
                continue; 
            }
            pos[c] = end++;
        }
        // if string ends
        ans = max(ans, end - start);

        return ans;
    }
};