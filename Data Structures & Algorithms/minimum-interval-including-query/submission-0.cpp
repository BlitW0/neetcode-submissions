class Solution {
public:
    using pi = pair <int, int>;

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector <int> ans(n);
        vector <pi> q(n);

        for (int i = 0; i < n; i++)
            q[i] = {queries[i], i};
        sort(q.begin(), q.end());

        // sort by start time
        sort(intervals.begin(), intervals.end(),
            [](const auto& a, const auto& b) {
                return a[0] < b[0];
            });
        priority_queue <pi, vector <pi>, greater <> > pq;

        int i = 0, m = intervals.size();
        for (auto [num, idx] : q) {
            // add intervals whose start reached
            while (i < m && intervals[i][0] <= num) {
                int s = intervals[i][0], e = intervals[i][1];
                pq.push({e - s + 1, e});
                i++;
            }

            // remove intervals with end smaller (passed them)
            while (!pq.empty() && pq.top().second < num)
                pq.pop();
            
            if (pq.empty()) {
                ans[idx] = -1;
                continue;
            }

            auto [len, e] = pq.top();
            int s = e - len + 1;
            if (s <= num && num <= e)
                ans[idx] = len;
            else
                ans[idx] = -1;
        }

        return ans;
    }
};