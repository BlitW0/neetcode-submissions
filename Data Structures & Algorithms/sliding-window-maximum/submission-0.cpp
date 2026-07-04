class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1)
            return nums;
        
        // maintains decr order of nums in cur k window
        deque <int> dec; 
        vector <int> ans;

        for (int i = 0; i < n; i++) {
            // remove all lesser nums from back, then push
            while (not dec.empty() and dec.back() < nums[i])
                dec.pop_back();
            dec.push_back(nums[i]);

            // if win size reaches k, remove nums[i - k] from window
            // and deque if it was win max (in front)
            if (i >= k and nums[i - k] == dec.front())
                dec.pop_front();

            // deque front is window max
            if (i >= k - 1) ans.push_back(dec.front());
        }

        return ans;
    }
};