class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // make sure num1 is smaller
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = n1, mid1, mid2, n = n1 + n2;
        int left = (n + 1) / 2; // num elements to left of median

        while (lo <= hi) {
            mid1 = (lo + hi) >> 1;
            mid2 = left - mid1;

            // boundary numbers
            // elem from 1 and 2 included to left of median
            int l1 = INT_MIN, l2 = INT_MIN;
            // elem from 1 and 2 included to right of median
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if (l1 <= r2 and l2 <= r1) {
                // odd size total
                if (n & 1) return max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) hi = mid1 - 1;
            else lo = mid1 + 1;
        }
        return 0;
    }
};