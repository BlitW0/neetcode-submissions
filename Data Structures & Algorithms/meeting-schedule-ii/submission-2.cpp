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

        int n = intervals.size();
        vector <int> start(n), end(n);
        for (int i = 0; i < n; i++)
            start[i] = intervals[i].start, end[i] = intervals[i].end;
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0, count = 0, ans = 0;
        while (i < n and j < n) {
            if (start[i] < end[j])
                i++, count++;
            else
                j++, count--;
            ans = max(ans, count);
        }

        return ans;
    }
};
