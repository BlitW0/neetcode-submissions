class Solution {
public:
    typedef vector <int> vi;

    void solve(int idx, vi& nums, vi& subs, vector <vi>& ans) {
        ans.push_back(subs);

        // try adding all elements in subs while skipping dups
        for (int i = idx; i < nums.size(); i++) {
            // skip dups on same recursion level
            if (i > idx and nums[i] == nums[i - 1])
                continue;

            subs.push_back(nums[i]);
            solve(i + 1, nums, subs, ans);
            subs.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort to efficiently avoid dups
        sort(nums.begin(), nums.end());

        vector <vi> ans;
        vi subs;
        solve(0, nums, subs, ans);

        return ans;
    }
};