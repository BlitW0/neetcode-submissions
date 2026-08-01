class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 0, prev1 = 1, cur;
        while (n--) {
            cur = prev1 + prev2;
            prev2 = prev1, prev1 = cur;
        }
        return cur;
    }
};
