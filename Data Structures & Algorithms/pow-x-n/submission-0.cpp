class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1.00)
            return 1;
        
        return n > 0 ? bexp(x, n) : bexp(1/x, -1 * (unsigned int) n);
    }

    double bexp(double x, unsigned int n) {
        double ans = 1;
        while (n) {
            if (n & 1) ans *= x;
            x *= x, n >>= 1;
        }
        return ans;
    }
};