class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty())
            return 0;
        
        int pos = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] != val)
                nums[pos++] = nums[i];
        
        return pos;
    }
};