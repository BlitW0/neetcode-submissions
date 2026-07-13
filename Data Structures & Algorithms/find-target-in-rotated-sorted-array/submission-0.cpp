class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            if (nums[mid] == target)
                return mid;

            // left half is sorted
            if (nums[lo] <= nums[mid]) {
                // if target there, search in that half
                if (nums[lo] <= target and target <= nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            } else { // right half is sorted
                // if target there, search in that half
                if (nums[mid] <= target and target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return -1;
    }
};