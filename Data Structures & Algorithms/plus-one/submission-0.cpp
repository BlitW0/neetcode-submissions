class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            carry = sum / 10, sum = sum % 10;
            digits[i] = sum;
            if (not carry)
                return digits;
        }
        
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
