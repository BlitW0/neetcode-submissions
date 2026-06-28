class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int cnt[20001] = {0}, mn = INT_MAX, mx = INT_MIN, ofs = 10000;

        for (int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
            cnt[num + ofs]++;
        }
        
        for (int i = mx; i >= mn; i--) {
            int numcnt = cnt[i + ofs];

            if (numcnt)
                k -= numcnt;
            if (k <= 0)
                return i;
        }
        
        return nums[0];
    }
};