class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Greedy: Find max non overlapping intervals
        // return n - above
        // Sort by end values, always pick one with least end value
        // If found overlapping with last picked, discard interval

        bool sorted = true;
        int n = intervals.size();

        // check if intervals are sorted by end values
        for (int i = 1; i < n; i++)
            if (intervals[i - 1][1] > intervals[i][1]) {
                sorted = false;
                break;
            }
        
        // If not sorted, sort by end values
        if (!sorted) {
            sort(intervals.begin(), intervals.end(), [](const vector <int>& a, const vector <int>& b){
                if (a[1] == b[1])
                    return a[0] < b[0];
                return a[1] < b[1];
            });
        }

        int x = intervals[0][0], y = intervals[0][1], ans = 0;
        
        for (int i = 1; i < n; i++) {
            int nx = intervals[i][0], ny = intervals[i][1];
            
            // If new interval overlaps with existing ones, discard it because we have only chosen the ones with least end values so discarding it won't compromise optimal solution
            if (nx < y) ans++;
            else x = nx, y = ny;
        }

        return ans;
    }
};