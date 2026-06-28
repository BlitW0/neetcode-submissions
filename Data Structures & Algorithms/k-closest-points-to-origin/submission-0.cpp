class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue <pair <int, int> > mxheap;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0], y = points[i][1];
            
            mxheap.push( {sqEucDist(x, y), i} );
            if (mxheap.size() > k)
                mxheap.pop();
        }

        vector <vector <int> > ans;
        while (!mxheap.empty()) {
            pair <int, int> tp = mxheap.top();
            ans.push_back(points[tp.second]);
            mxheap.pop();
        }

        return ans;
    }

private:
    int sqEucDist(int x, int y) {
        return x*x + y*y;
    }
};