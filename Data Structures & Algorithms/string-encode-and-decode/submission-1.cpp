class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string ret;
        for (string s : strs) {
            ret.append(to_string(s.size()));
            ret.push_back('#');
            ret.append(s);
        }
        
        return ret;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        vector <string> ret;
        for (int i = 0; i < s.length(); ) {
            int j = i;
            while (j < s.length() and s[j] != '#') j++; // j ends when char is #

            int len = stoi(s.substr(i, j - i));
            j += 1;
            ret.push_back(s.substr(j, len));
            i = j + len;
        }
        return ret;
    }
};
