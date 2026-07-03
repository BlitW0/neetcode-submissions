class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // keep latest character pos, update and jump directly
        vector <int> lastpos(256, -1); // ascii 256
        int st = 0, ans = 0, n = s.length();

        for (int en = 0; en < n; en++) {
            // move l to after last pos of this character to avoid dups
            st = max(st, lastpos[s[en]] + 1);

            // update last pos of char
            lastpos[s[en]] = en;
            
            ans = max(ans, en - st + 1);
        }

        return ans;
    }
};
