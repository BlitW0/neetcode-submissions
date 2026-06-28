class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
               st.push(c); 
            } else {
                if (st.empty()) return false;
                char tp = st.top();
                if ((tp == '(' && c != ')') ||
                    (tp == '[' && c != ']') || 
                    (tp == '{') && c != '}')
                    return false;
                st.pop();
            }
        }
        return st.empty();        
    }
};
