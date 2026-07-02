class Solution {
public:
    typedef pair <int, int> pi;
    vector <pi> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    const int INF = INT_MAX;

    bool check(int x, int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }

    void visit(queue <pair <pi, int> >& q, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        while (not q.empty()) {
            auto f = q.front();
            q.pop();

            pi pos = f.first;
            int dis = f.second;

            int x = pos.first, y = pos.second;
            for (auto d : dir) {
                int px = x + d.first, py = y + d.second;
                if (check(px, py, n, m)) {
                    int val = grid[px][py];
                    if (val == -1) continue;

                    if (dis + 1 < val) {
                        grid[px][py] = dis + 1;
                        q.push({{px, py}, dis + 1});
                    }
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue <pair <pi, int> > q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 0)
                    q.push({{i, j}, 0});
        visit(q, grid);
    }
};
