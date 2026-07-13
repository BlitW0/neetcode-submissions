class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // use numbers in array as indices, since its in [1..n]
        // we can just mark the num at index nums[i] as negative
        // when we find dup, we check if it was alread marked

        for (auto num : nums) {
            int idx = abs(num) - 1;
            if (nums[idx] < 0)
                return abs(num);
            nums[idx] *= -1;
        }
        return 0;
    }
};