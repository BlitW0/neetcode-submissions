class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0, ans = 0;
        for (int i = 0; i < 32; i++) {
            int x = a & (1 << i), y = b & (1 << i);
            ans |= (x ^ y ^ (carry << i));
            carry = ((x ^ y) and carry) or (x and y);
        }
        return ans;
    }
};
