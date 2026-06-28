class Solution {
public:

    string encode(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string ret;
        for (string s : strs) {
            ret.append(to_string(s.size()));
            ret.push_back(',');
        }
        ret.push_back('#');
        for (string s : strs)
            ret.append(s);
        
        return ret;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};

        vector <string> ret;
        vector <int> sizes;

        // cout << s << '\n';
        
        int i = 0;
        string cur;
        while (s[i] != '#') {
            while (s[i] != ',')
                cur += s[i++];
            // cout << cur << ' ' << i << '\n';
            sizes.push_back(stoi(cur));
            cur.clear();
            i++;
        }
        i += 1;

        for (int x : sizes) {
            ret.push_back(s.substr(i, x));
            i += x;
        }

        return ret;
    }
};
