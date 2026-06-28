class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Keep 2 pointers, 1 for where you want to reach and other for
        // where you can reach the pointer 1 from.
        //
        // If it is possible to reach 1st pointer, we move 1st pointer to
        // 2nd pointer position and move 2nd pointer 1 position back to see
        // if we can reach 2nd pointer from some position in the back.

        int n = nums.size();
        int goal = n - 1;

        // goal = 1st pointer
        // i = 2nd pointer
        for (int i = n - 2; i >= 0; i--)
            if (i + nums[i] >= goal) // We can go from i to goal, now set goal to i and find some index before i which can reach i
                goal = i;

        return goal == 0;
    }
};