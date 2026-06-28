class Solution {
public:
    typedef vector <int> vi;

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        bool sorted = true;
        int n = intervals.size();

        for (int i = 1; i < n; i++)
            if (intervals[i - 1] > intervals[i]) {
                sorted = false;
                break;
            }

        if (!sorted)
            sort(intervals.begin(), intervals.end());
        vector <vi> ans;

        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            int nx = intervals[i][0], ny = intervals[i][1], y = ans.back()[1];

            if (nx <= y)
                ans.back()[1] = max(y, ny);
            else
                ans.push_back(intervals[i]);
        }

        return ans;
    }
};