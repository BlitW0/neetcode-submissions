class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> l(n), r(n); // tallest bar to left and right of i

        l[0] = INT_MIN;
        for (int i = 1; i < n; i++)
            l[i] = max(l[i - 1], height[i - 1]);
        
        r[n - 1] = INT_MIN;
        for (int i = n - 2; i >= 0; i--)
            r[i] = max(r[i + 1], height[i + 1]);

        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            ans += max(0, min(l[i], r[i]) - height[i]);
        return ans;
    }
};
