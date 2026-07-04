class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        int cnt1[26] = {0}, a = s1.length();
        for (auto c : s1)
            cnt1[c - 'a']++;
        
        int cnt2[26] = {0}, b = s2.length();
        for (int i = 0; i < b; i++) {
            cnt2[s2[i] - 'a']++;
            if (i >= a) cnt2[s2[i - a] - 'a']--;

            bool chk = true;
            for (int c = 0; c < 26; c++)
                if (cnt1[c] != cnt2[c]) {
                    chk = false; 
                    break;
                }
            
            if (chk) return true;
        }

        return false;
    }
};