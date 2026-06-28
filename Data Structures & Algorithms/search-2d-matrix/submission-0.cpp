class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // which row
        int n = matrix.size(), m = matrix[0].size();
        int lo = 0, hi = n - 1, row = -1;
        while (lo <= hi) {
            int mid = (hi + lo) >> 1;
            int num = matrix[mid][0];

            if (num == target)
                return true;
            else if (num < target) {
                if (mid == n - 1 || (mid + 1 < n && matrix[mid + 1][0] > target)) {
                    row = mid;
                    break;
                }
                lo = mid + 1; 
            } else {
                hi = mid - 1;
            }
        }
        if (row == -1) 
            return false;

        // which column
        lo = 0, hi = m - 1;
        while (lo <= hi) {
            int mid = (hi + lo) >> 1;
            int num = matrix[row][mid];

            if (num == target) return true;
            else if (num > target) hi = mid - 1;
            else lo = mid + 1;
        }

        return false;
    }
};