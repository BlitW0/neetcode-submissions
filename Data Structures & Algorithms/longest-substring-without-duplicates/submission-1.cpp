class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set <char> seen;
        int l = 0, r = 0, n = s.length(), ans = 0;

        // move r to right if that char hasn't been seen before
        // move l to right to remove characters until repeating
        // one is removed
        while (r < n) {
            if (seen.contains(s[r])) {
                seen.erase(s[l++]);
            } else {
                seen.insert(s[r++]);
                ans = max(ans, r - l);
            }
        }

        return ans;
    }
};
