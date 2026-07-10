class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> ans(n, 0);
        stack <int> nxtgrter;
        
        for (int i = n - 1; i >= 0; i--) {
            while (not nxtgrter.empty() 
                    and temperatures[nxtgrter.top()] <= temperatures[i])
                nxtgrter.pop();
            
            ans[i] = nxtgrter.empty() ? 0 : nxtgrter.top() - i;
            nxtgrter.push(i);
        }

        return ans;
    }
};