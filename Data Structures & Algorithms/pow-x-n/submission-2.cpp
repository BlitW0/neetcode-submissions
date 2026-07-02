class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long pow = abs((long) n);
        for (; pow; pow >>= 1, x = x*x)
            if (pow & 1)
                ans *= x;
        return n >= 0 ? ans : 1/ans;
    }
};
