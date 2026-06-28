class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's Algo
        // Keep a running sum, and reset it if it becomes lesser than the
        // current element. Keep track of the max sum found till ending at 
        // each element.

        int subsum = 0, maxsum = INT_MIN;
        for (int num : nums) {
            subsum = max(num, subsum + num);
            maxsum = max(maxsum, subsum);
        }
        return maxsum;
    }
};