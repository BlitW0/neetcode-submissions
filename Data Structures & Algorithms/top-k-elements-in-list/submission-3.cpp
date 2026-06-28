class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> cnt;
        for (int x : nums)
            cnt[x]++;
        
        vector <vector <int> > freq(nums.size() + 1);
        for (auto p : cnt)
            freq[p.second].push_back(p.first);
        
        vector <int> ans;
        for (int i = freq.size() - 1; i >= 1; i--)
            while (not freq[i].empty() and ans.size() < k) {
                ans.push_back(freq[i].back());
                freq[i].pop_back();
            }
        return ans;
    }
};
