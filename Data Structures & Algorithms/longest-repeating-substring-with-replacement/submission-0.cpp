class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0, end = 0, cnt[26] = {0}, ans = 1, len = s.length();

        while (end < len) {
            cnt[s[end] - 'A']++;

            int sublen = end - start + 1;
            int cntmx = *max_element(cnt, cnt + 26);

            if (sublen - cntmx > k) {
                cnt[s[start++] - 'A']--;
            } else {
                ans = max(ans, sublen);
            }
            end++;
        }
        
        return ans;
    }
};