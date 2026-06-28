class Solution {
public:
    typedef pair<int, int> pii;
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <pii> st;
        int n = temperatures.size();
        vector <int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temperatures[i])
                st.pop();
            ans[i] = st.empty() ? 0 : st.top().second - i;
            st.push({temperatures[i], i});
        }

        return ans;
    }
};