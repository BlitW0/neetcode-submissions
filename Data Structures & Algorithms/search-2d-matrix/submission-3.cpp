class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        if (target < matrix[0][0] or target > matrix.back().back())
            return false;

        int lo = 0, hi = n*m - 1, mid;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;

            // indices are repeating chunks of m numbers
            // starting at multiple of m
            // ex. {0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}, ...
            int r = mid / m, c = mid % m;
            int val = matrix[r][c];

            if (target == val) return true;
            else if (val > target) hi = mid - 1;
            else lo = mid + 1;
        }

        return false;
    }
};
