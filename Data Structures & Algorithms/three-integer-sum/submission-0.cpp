class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector <int> > ans;
        set <vector <int> > seen;
        int n = nums.size();

        for (int i = 0; i + 2 < n; i++) {
            int target = -nums[i];

            unordered_map <int, int> idx;
            for (int k = i + 1; k < n; k++) {
                int x = nums[k];
                if (idx.contains(target - x)) {
                    vector <int> temp = {-target, x, nums[idx[target - x]]};
                    sort(temp.begin(), temp.end());
                    seen.insert(temp);
                }
                idx[x] = k;
            }
        }

        for (auto v : seen)
            ans.push_back(v);
        return ans;
    }
};
