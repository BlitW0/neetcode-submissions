class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> tails; // tails[i] = least value at which lis of length i+1 ends

        tails.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (tails.back() < nums[i]) {
                tails.push_back(nums[i]);
                continue;
            }
            auto it = lower_bound(tails.begin(), tails.end(), nums[i]);
            if (*it > nums[i]) *it = nums[i];
        }
        return tails.size();
    }
};