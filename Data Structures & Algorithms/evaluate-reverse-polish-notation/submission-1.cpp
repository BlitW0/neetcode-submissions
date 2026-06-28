class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for (string s : tokens) {
            if (s != "+" && s != "*" && s != "-" && s != "/")
                st.push(stoi(s));
            if (s == "+") {
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();
                st.push(x + y);
            }
            if (s == "*") {
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();
                st.push(x * y);
            }
            if (s == "-") {
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();
                st.push(x - y);
            }
            if (s == "/") {
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();
                st.push(x / y);
            }
        }
        return st.top();
    }
};