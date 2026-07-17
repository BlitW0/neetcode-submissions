class Solution {
public:
    int jump(vector<int>& nums) {
        // l..r farthest range of indices possible with x steps
        int l = 0, r = 0, steps = 0;

        while (r < nums.size() - 1) {
            int far = 0;
            for (int i = l; i <= r; i++)
                far = max(far, i + nums[i]);
            l = r + 1;
            r = far;
            steps++;
        }

        return steps;
    }
};