class Solution {
public:
    using T = tuple <int, int, int>;

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector time(n, vector <int> (n, INT_MAX));
        
        auto invalid = [&](int x, int y) {
            return x < 0 or x >= n or y < 0 or y >= n;
        };
        const vector <pair <int, int> > dir = {
            {1, 0}, {-1, 0}, {0, -1}, {0, 1}
        };

        priority_queue <T, vector <T>, greater <> > pq;
        pq.push({0, 0, grid[0][0]});
        time[0][0] = grid[0][0];

        while (not pq.empty()) {
            auto [r, c, t] = pq.top();
            pq.pop();

            if (t > time[r][c])
                continue;
            if (r == n - 1 and c == n - 1)
                return t;
            
            for (auto [dr, dc] : dir) {
                int nr = r + dr, nc = c + dc;
                if (invalid(nr, nc))
                    continue;
                
                int mx = max(t, grid[nr][nc]);
                if (mx < time[nr][nc]) {
                    time[nr][nc] = mx;
                    pq.push({nr, nc, mx});
                }
            }
        }

        return -1;
    }
};