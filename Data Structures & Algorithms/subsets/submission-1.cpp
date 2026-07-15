class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1 << nums.size();
        vector <vector <int> > ans(n);

        for (int val = 0; val < n; val++)
            for (int i = 0; i < nums.size(); i++)
                if ((val >> i) & 1)
                    ans[val].push_back(nums[i]);
        
        return ans;
    }
};