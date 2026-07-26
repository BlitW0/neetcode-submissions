class Solution {
public:
    typedef pair <int, int> pi;

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        if (n == 1 and m == 1)
            return 0;
        
        // dijkstra with cost = min diff on path till current cell
        vector <int> cost(n*m + 1, INT_MAX);
        priority_queue <pi, vector <pi>, greater<> > pq;

        vector <pi> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto valid = [&](int x, int y) {
            return x >= 0 and x < n and y >= 0 and y < m;
        };

        cost[0] = 0;
        pq.push({0, 0});
        while (not pq.empty()) {
            auto [c, idx] = pq.top(); pq.pop();
            if (c > cost[idx]) continue;

            int x = idx / m, y = idx % m;
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (not valid(nx, ny)) continue;

                int nidx = nx*m + ny, w = abs(heights[x][y] - heights[nx][ny]);

                if (max(c, w) < cost[nidx]) {
                    cost[nidx] = max(c, w);
                    pq.push({cost[nidx], nidx});
                }
            }

        }
        return cost[n*m - 1];
    }
};