class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1, mid, ans = INT_MAX;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;

            // range is already sorted, no need to search more
            if (nums[lo] <= nums[hi]) {
                ans = min(ans, nums[lo]);
                break;
            }
            
            // sorted half can't give anything smaller than
            // its min, so discard it and search other half

            // left half sorted, take min and search in right
            if (nums[lo] <= nums[mid])
                ans = min(ans, nums[lo]), lo = mid + 1;
            else // right half sorted, take min and search in left
                ans = min(ans, nums[mid]), hi = mid - 1;
        }
        return ans;
    }
};