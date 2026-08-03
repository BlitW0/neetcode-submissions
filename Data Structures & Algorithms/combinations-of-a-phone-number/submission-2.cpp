class Solution {
public:
    unordered_map <char, string> letters = {
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector <string> ans = {""};

        for (int i = 0; i < digits.size(); i++) {
            vector <string> nxt;
            for (string s : ans)
                for (char c : letters[digits[i]])
                    nxt.push_back(s + c);
            ans = nxt;
        }

        return ans;
    }
};