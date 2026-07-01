class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;

        while (lo <= hi) {
            int m = (lo + hi) >> 1;

            if (nums[m] == target) return m;
            else if (target > nums[m]) lo = m + 1;
            else hi = m - 1;
        }

        return -1;
    }
};
