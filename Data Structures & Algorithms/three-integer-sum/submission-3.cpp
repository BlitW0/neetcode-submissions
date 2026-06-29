class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector <int> > ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < n; i++) {
            if (i > 0 and nums[i] == nums[i - 1])
                continue;

            int target = -nums[i];

            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[j] + nums[k];

                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++, k--;
                    while (j < k and nums[j] == nums[j - 1]) j++;
                }
                else if (sum < target) j++;
                else k--;
            }
        }

        return ans;
    }
};
