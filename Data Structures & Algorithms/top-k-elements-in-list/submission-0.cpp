class Solution {
public:
    typedef pair <int, int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> cnt(2e4 + 1, 0);
        for (int x : nums)
            cnt[x + 1e4]++;
        priority_queue <pii, vector <pii>, greater<pii> > hp;
        for (int i = -1e4; i <= 1e4; i++) {
            if (cnt[i + 1e4] != 0)
                hp.push({cnt[i + 1e4], i});
            if (hp.size() > k)
                hp.pop();
        }
        vector <int> ans;
        while (!hp.empty()) {
            pair <int, int> tp = hp.top();
            ans.push_back(tp.second);
            hp.pop();
        }
        return ans;
    }
};
