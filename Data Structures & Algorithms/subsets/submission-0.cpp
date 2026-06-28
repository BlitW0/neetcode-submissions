class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1 << nums.size();
        vector <vector <int> > ans;
        for (int i = 0; i < n; i++) {
            vector <int> cur_sub;
            for (int idx = 0, val = i; val; val >>= 1, idx++)
                if (val & 1)
                    cur_sub.push_back(nums[idx]);
            ans.push_back(cur_sub);
        }
        return ans;
    }
};