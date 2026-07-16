class Solution {
public:
    typedef pair <int, int> pi;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        const vector <pi> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        auto valid = [&](int x, int y) { return x >= 0 and x < n and y >= 0 and y < m; };

        vector indeg(n, vector <int> (m, 0));

        // calc indegs for all nodes
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
                for (auto [dx, dy] : dir) {
                    int nx = x + dx, ny = y + dy;
                    if (valid(nx, ny) and matrix[x][y] < matrix[nx][ny])
                        indeg[nx][ny]++;
                }

        // multi-source bfs, push nodes with indeg 0
        queue <pi> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (not indeg[i][j])
                    q.push({i, j});

        int lis = 0;
        while (not q.empty()) {
            // process all nodes on this level
            int sz = q.size();
            lis++; // subseq increases by 1 with every level
            
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                int val = matrix[x][y];

                for (auto [dx, dy] : dir) {
                    int nx = x + dx, ny = y + dy;
                    if (valid(nx, ny) and val < matrix[nx][ny])
                        if (not --indeg[nx][ny])
                            q.push({nx, ny});
                }
            }
        }
        return lis;
    }
};