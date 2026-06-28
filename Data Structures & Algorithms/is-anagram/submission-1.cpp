class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnts[26] = {0}, cntt[26] = {0};
        for (auto c : s) cnts[c - 'a']++;
        for (auto c : t) cntt[c - 'a']++;

        for (int i = 0; i < 26; i++)
            if (cnts[i] != cntt[i])
                return false;
        return true;
    }
};
