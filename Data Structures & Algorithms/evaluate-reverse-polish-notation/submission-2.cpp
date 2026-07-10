class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;

        auto calc = [](int x, int y, char op) {
            switch (op) {
                case '+': return x + y;
                case '-': return x - y;
                case '*': return x * y;
                case '/': return x / y;
            };
            return 0;
        };

        for (string t : tokens) {
            bool chk = (t[0] >= '0' and t[0] <= '9') or (t[0] == '-' and t.length() > 1);

            if (not chk) {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                s.push(calc(x, y, t[0]));
            } else s.push(stoi(t));
        }

        return s.top();
    }
};