class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        if (nums.empty())
            return nums;
        
        int n = nums.size();
        vector <int> ans(n << 1);
        for (int i = 0; i < (n << 1); i++)
            ans[i] = nums[i % n];
        
        return ans;
    }
};