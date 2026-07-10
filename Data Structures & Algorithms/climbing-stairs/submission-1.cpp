class Solution {
public:
    int climbStairs(int n) {
        int a = 0, b = 1, c;
        while (n--) {
            // dp[n] = dp[n - 2] + dp[n - 1]
            c = a + b;
            a = b, b = c;
        }
        return c;
    }
};