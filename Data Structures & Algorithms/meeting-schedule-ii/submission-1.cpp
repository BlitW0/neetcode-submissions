/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    typedef pair <int, int> pi;

    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(),
                [](const Interval& x, const Interval& y) {
                    if (x.start != y.start)
                        return x.start < y.start;
                    return x.end < y.end;
                });
        
        int ans = 0;
        priority_queue <pi, vector <pi>, greater <pi> > pq;
        for (auto inter : intervals) {
            while (not pq.empty()) {
                auto t = pq.top();
                if (t.first <= inter.start)
                    pq.pop();
                else break;
            }
            pq.push({inter.end, inter.start});
            ans = max(ans, (int) pq.size());
        }
        return ans;
    }
};
