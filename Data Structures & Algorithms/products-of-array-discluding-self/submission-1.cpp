class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums;

        vector <int> suf(n, 1), ans(n);
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] * nums[i + 1];
        
        int pref = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = pref * suf[i];
            pref *= nums[i];
        }
        return ans;
    }
};
