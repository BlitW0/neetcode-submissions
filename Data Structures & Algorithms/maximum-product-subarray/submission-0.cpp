class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Logic
        // If 0 is found, we have to restart to product
        // There will be even or odd negative numbers in between these 0s
        //  If there are even, then we can include them all
        //  If there are odd,
        //      We know that answer subarray will be either to the left
        //      or right of one of these negative numbers. The subarray
        //      may contain some even negative numbers, but that will be
        //      included in the running product. So, since the subarray
        //      can be on the left or right, we can try running product
        //      from both sides and see which one gives the optimal answer. 

        int leftmax = INT_MIN, rightmax = INT_MIN, curprod = 1;

        for (int i = 0; i < nums.size(); i++) {
            curprod *= nums[i];
            leftmax = max(leftmax, curprod);
            if (curprod == 0) curprod = 1;
        }

        curprod = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            curprod *= nums[i];
            rightmax = max(rightmax, curprod);
            if (curprod == 0) curprod = 1;
        }

        return max(leftmax, rightmax);
    }
};