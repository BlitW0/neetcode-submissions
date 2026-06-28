class Solution {
public:
    typedef pair <int, int> pii;

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector <pii> ans;
        for (auto inter : intervals)
            ans.push_back({inter[0], inter[1]});
        ans.push_back({newInterval[0], newInterval[1]});

        sort(ans.begin(), ans.end());

        vector <vector <int> > ret;
        for (pii inter : ans) {
            int nx = inter.first, ny = inter.second, x = -1, y = -1;
            if (!ret.empty()) {
                x = ret.back()[0], y = ret.back()[1];
                if (nx <= y) {
                    nx = min(x, nx), ny = max(y, ny);
                    ret.pop_back();
                }
            }
            ret.push_back({nx, ny});
        }

        return ret;
    }
};