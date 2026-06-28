class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int offs = 1000;

        int cnt[2000 + 10] = {0};
        for (int x : nums)
            cnt[x + offs]++;
        
        priority_queue <pair <int, int> > pq;
        for (int i = 0; i < 2010; i++)
            if (cnt[i])
                pq.push({cnt[i], i - offs});

        vector <int> ans;
        while (ans.size() != k) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
