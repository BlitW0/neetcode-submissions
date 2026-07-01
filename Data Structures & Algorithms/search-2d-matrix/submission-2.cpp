class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        if (target < matrix[0][0] or target > matrix.back().back())
            return false;

        int row = 0, lo = 0, hi = n - 1, mid;

        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            int val = matrix[mid][0];

            if (mid < n - 1) {
                int val2 = matrix[mid + 1][0];

                // target must lie in row that starts with mid
                if (val <= target and target < val2) break;
                else if (val > target) hi = mid - 1;
                else lo = mid + 1; 
            } else break;
        }

        row = mid;
        // found at row start
        if (matrix[row][0] == target)
            return true;
        
        lo = 0, hi = m - 1;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            int val = matrix[row][mid];

            if (val == target) return true;
            else if (target > val) lo = mid + 1;
            else hi = mid - 1;
        }

        return false;
    }
};
