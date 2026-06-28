class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        const int offs = 1000;

        int cnt[2000 + 10] = {0}, n = nums.size();
        for (int x : nums)
            cnt[x + offs]++;
        
        vector <vector <int> > freq(n + 1, vector <int> ());
        for (int x = -offs; x <= offs; x++)
            if (cnt[x + offs])
                freq[cnt[x + offs]].push_back(x);
        
        vector <int> ans;
        for (int i = n; i >= 1; i--)
            while (not freq[i].empty() and ans.size() < k) {
                ans.push_back(freq[i].back());
                freq[i].pop_back();
            }
        return ans;
    }
};
