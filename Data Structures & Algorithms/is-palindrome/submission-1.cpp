class Solution {
public:
    bool valid(char c) {
        return (c >= '0' and c <= '9') or (tolower(c) >= 'a' and tolower(c) <= 'z');
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;

        while (i < j) {
            while (not valid(s[i]) and i < j) i++;
            while (not valid(s[j]) and i < j) j--;

            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++, j--;
        }

        return true;
    }
};
