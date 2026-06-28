class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash_table;
        for (int x : nums) {
            if (hash_table.find(x) != hash_table.end())
                return true;
            hash_table[x] = 1;
        }
        return false;
    }
};
