class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector <vector <int> > ans;
        if (candidates.empty())
            return ans;
        if (!target) {
            ans.push_back(vector <int>());
            return ans;
        }
        
        int cand = candidates.back();
        
        // Don't use current candidate
        candidates.pop_back();
        for (auto prev : combinationSum(candidates, target))
            ans.push_back(prev);
        candidates.push_back(cand);
        
        // Use current candidate
        if (cand <= target) {
            for (auto prev : combinationSum(candidates, target - cand)) {
                prev.push_back(cand);
                ans.push_back(prev);
            }
        }
        
        return ans;
    }
};