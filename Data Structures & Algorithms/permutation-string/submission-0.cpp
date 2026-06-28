class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int permcnt[26] = {0}, cnt[26] = {0}, permlen = s1.length();
        bool found = 0;

        for (char c : s1)
            permcnt[c - 'a']++;
        for (int i = 0; i < s2.length(); i++) {
            // sliding window of length of s1
            cnt[s2[i] - 'a']++;
            if (i >= permlen) {
                cnt[s2[i - permlen] - 'a']--;
            }

            bool match = 1;
            for (int j = 0; j < 26; j++)
                if (cnt[j] != permcnt[j]) {
                    match = 0;
                    break;
                }
            if (match) return found = 1;
        }

        return found;
    }
};