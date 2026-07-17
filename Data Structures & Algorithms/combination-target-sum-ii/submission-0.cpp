class Solution {
public:
    typedef vector <int> vi;

    void solve(int i, int target, vi& nums, vi& comb, vector <vi>& ans) {
        if (target == 0) {
            ans.push_back(comb);
            return;
        }
        for (int idx = i; idx < nums.size(); idx++) {
            // skip duplicates on same recursion level
            if (idx > i and nums[idx] == nums[idx - 1])
                continue;
            if (nums[idx] > target) break;
            
            // take
            comb.push_back(nums[idx]);
            solve(idx + 1, target - nums[idx], nums, comb, ans);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        // nums should be sorted to efficiently discard duplicates
        sort(nums.begin(), nums.end());

        vector <vi> ans;
        vi comb;
        solve(0, target, nums, comb, ans);
        return ans;
    }
};