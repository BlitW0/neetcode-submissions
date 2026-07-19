class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 1) return 0;

        sort(intervals.begin(), intervals.end(), 
            [](const auto &x, const auto &y) {
                return x[1] < y[1];
            });

        int prevend = intervals[0][1], ans = 0;
        for (int i = 1; i < n; i++) {
            if (prevend > intervals[i][0])
                ans++;
            else
                prevend = intervals[i][1];
        }
        return ans;
    }
};