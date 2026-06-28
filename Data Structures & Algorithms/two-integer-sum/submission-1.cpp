class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> idx;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i], y = target - nums[i];
            if (idx.find(y) != idx.end())
                return {idx[y], i};
            idx[x] = i;
        }
        return {};
    }
};
