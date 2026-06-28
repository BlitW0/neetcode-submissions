class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min = prices[0], ans = 0;
        for (int x : prices) {
            ans = max(ans, x - cur_min);
            cur_min = min(cur_min, x);
        }
        return ans;
    }
};