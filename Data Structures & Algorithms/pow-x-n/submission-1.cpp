class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if (n < 0)
            n = -n, x = 1/x;
        for (; n; n >>= 1, x = x*x)
            if (n & 1)
                ans *= x;
        return ans;
    }
};
