class Solution {
public:
    int characterReplacement(string s, int k) {
        int cnt[26] = {0}, ans = 1, st = 0;

        for (int en = 0; en < s.length(); en++) {
            cnt[s[en] - 'A']++;
            int mxcnt = *max_element(cnt, cnt + 26), len = en - st + 1;
            
            // repl needed more than k, move st ptr to right
            if (len - mxcnt > k) {
                cnt[s[st++] - 'A']--;
                continue;
            }
            ans = max(ans, len);
        }

        return ans;
    }
};