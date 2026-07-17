class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // running sum, either reset or keep going greedily
        // check max everytime
        int sum = 0, mxsum = INT_MIN;
        for (int num : nums) {
            sum = max(num, sum + num);
            mxsum = max(mxsum, sum);
        }
        return mxsum;
    }
};