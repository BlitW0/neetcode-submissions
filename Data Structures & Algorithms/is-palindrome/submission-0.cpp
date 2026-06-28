class Solution {
public:
    bool check(char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int f = 0, b = s.length() - 1;
        while (f < b) {
            char x = tolower(s[f]), y = tolower(s[b]);
            if (!check(x)) {
                f++; continue;
            }
            if (!check(y)) {
                b--; continue;
            }
            if (x != y) return false;
            f++, b--;
        }
        return true;
    }
};
