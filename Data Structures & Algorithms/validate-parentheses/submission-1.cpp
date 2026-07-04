class Solution {
public:
    bool isValid(string s) {
        vector <char> brac[2] = { {'(', '{', '['}, {')', '}', ']'} };

        auto pres = [&brac](char c, int x) {
            for (int i = 0; i < 3; i++)
                if (brac[x][i] == c)
                    return i;
            return -1;
        };

        stack <char> st;
        for (auto c : s) {
            if (pres(c, 0) != -1) {
                st.push(c);
                continue;
            }
            int idx = pres(c, 1); 
            if (idx != -1) {
                if (st.empty() or st.top() != brac[0][idx])
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};