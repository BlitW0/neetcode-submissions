class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int val = 0, n = nums.size();
        for (int i = 0; i <= n; i++)
            val ^= i;
        int arr = 0;
        for (int x : nums)
            arr ^= x;
        return val ^ arr;
    }
};
