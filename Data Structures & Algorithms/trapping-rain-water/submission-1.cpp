class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        int lmax = 0, rmax = 0, i = 0, j = n - 1;

        while (i < j) {
            lmax = max(lmax, height[i]);
            rmax = max(rmax, height[j]);

            // lmax < rmax means that any value we find on the right
            // will definitely be >= rmax (since rmax is doing max)
            // and it is not possible to get a bottleneck for the wall
            // on the right -> min(l, r) = l
            // same intuition on the left
            if (lmax < rmax) ans += lmax - height[i++];
            else ans += rmax - height[j--];
        }

        return ans;
    }
};
