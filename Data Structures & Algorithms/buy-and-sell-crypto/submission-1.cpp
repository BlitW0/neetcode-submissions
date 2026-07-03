class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // keep running minimum, use it as buy price
        int mn = prices[0], ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};
