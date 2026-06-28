class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // By default, every integer is an subseq of length 1
        // Let's try to find longest increasing subseq ending at element i
        // We need to find some element before i, which is smaller than
        // nums[i] and gives us better answer than our current one
        // So we run a nested loop of j, till i and update the answer for
        // each element nums[j] found that is smaller than nums[i]

        int n = nums.size();
        vector <int> lis(n, 1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i] and 1 + lis[j] > lis[i])
                    lis[i] = 1 + lis[j];
        
        return *max_element(lis.begin(), lis.end());
    }
};