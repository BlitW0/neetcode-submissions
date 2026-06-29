class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> pres;
        for (int x : nums)
            pres.insert(x);
        
        int mx = 0;
        for (int x : nums) {
            if (not pres.contains(x - 1)) {
                int last = x;
                while (pres.contains(last)) last++;
                mx = max(mx, last - x);
            }
        }
        return mx;
    }
};
