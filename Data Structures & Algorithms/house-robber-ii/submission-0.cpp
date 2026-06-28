class Solution {
public:
    int houseRobberClassic(vector <int>& nums) {
        // dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size(), ans1 = max(nums[1], nums[0]), ans2 = nums[0];
        int ans = max(ans1, ans2);
        for (int i = 2; i < n; i++) {
            ans = max(ans1, nums[i] + ans2);
            ans2 = ans1, ans1 = ans;
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return houseRobberClassic(nums);
        }
        // exclude nth house from answer
        vector <int> nums1(nums.begin(), nums.begin() + n - 1);
        // exclude 0th house from answer
        vector <int> nums2(nums.begin() + 1, nums.end());
        // return whichever is better
        return max(houseRobberClassic(nums1), houseRobberClassic(nums2));
    }
};