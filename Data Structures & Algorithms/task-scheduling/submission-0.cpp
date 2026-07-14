class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        for (char c : tasks)
            cnt[c - 'A']++;
        
        priority_queue <int> pq;
        for (int i = 0; i < 26; i++)
            if (cnt[i] > 0)
                pq.push(cnt[i]);
        
        queue <pair <int, int> > q;
        int time = 0;

        while (not pq.empty() or not q.empty()) {
            time++;

            if (pq.empty()) { 
                // no task to run, pick from cooldown
                // skip time to valid runtime of q front
                time = q.front().second;
            } else {
                // run task, red time by 1 and readd if non 0
                int mst = pq.top(); pq.pop();
                mst -= 1;
                if (mst) q.push({mst, time + n});
            }

            // task picked from cooldown, add to heap to run
            if (not q.empty() and q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};