class Solution {
public:
    int maxArea(vector<int>& heights) {
        // water = min(h[l], h[r]) * (r - l)

        int n = heights.size();
        int l = 0, r = n - 1, mx = 0;
        while (l < r) {
            mx = max(mx, min(heights[l], heights[r]) * (r - l));

            if (heights[l] < heights[r]) l++;
            else r--;
        }
        return mx;
    }
};
