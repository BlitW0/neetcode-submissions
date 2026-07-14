class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // places nth element in its right position in sorted order
        // without sorting the whole array using Quick Select
        // we need kth largest, so position is (n - k)
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n - k, nums.end());
        return nums[n - k];
    }
};