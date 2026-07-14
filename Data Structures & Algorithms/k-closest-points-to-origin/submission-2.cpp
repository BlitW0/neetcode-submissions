class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // runs quick select
        // places kth sorted element in its correct position
        // all elements before it are less than it but in random order
        nth_element(points.begin(), points.begin() + k - 1, points.end(), 
            [](const auto& p, const auto& q) {
                return p[0]*p[0] + p[1]*p[1] < q[0]*q[0] + q[1]*q[1];
            });
        return vector <vector <int> > (points.begin(), points.begin() + k);
    }
};