class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // area(i to j) = min(h[i..j]) * (j - i + 1)
        
        // consider for every bar i
        // i want to keep that factor constant as bottleneck
        // it will be min of all bar to left or right until a bar
        // smaller than it appears
        
        // so my area for i is h[i] * (idx of bar smaller on right - idx of bar smaller on left)
        // area is then (r - l - 1) * h[i]

        int n = heights.size();
        vector <int> r(n);
        stack <int> s;

        for (int i = n - 1; i >= 0; i--) {
            while (not s.empty() and heights[s.top()] >= heights[i])
                s.pop();
            r[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        while (not s.empty()) s.pop();

        int mxarea = 0, l;
        for (int i = 0; i < n; i++) {
            while (not s.empty() and heights[s.top()] >= heights[i])
                s.pop();
            l = s.empty() ? -1 : s.top();
            mxarea = max(mxarea, heights[i] * (r[i] - l - 1));
            s.push(i);
        }
        
        return mxarea;
    }
};