class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (; n; n >>= 1)
            ans += (n & 1);
        return ans;
    }
};
