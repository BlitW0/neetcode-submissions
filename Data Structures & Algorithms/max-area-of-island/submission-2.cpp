class Solution {
public:
    typedef pair <int, int> pi;

    int visit(int a, int b, vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        vector <pi> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        auto check = [&n, &m](int x, int y) {
            return x >= 0 and x < n and y >= 0 and y < m;
        };

        queue <pi> q;
        q.push({a, b});
        grid[a][b] = 2;

        while (not q.empty()) {
            auto c = q.front();
            q.pop();
            count++;
        
            int x = c.first, y = c.second;
            for (auto d : dir) {
                int px = x + d.first, py = y + d.second;
                if (check(px, py) and grid[px][py] == 1) {
                    grid[px][py] = 2;
                    q.push({px, py});
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), area = 0; 

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    area = max(area, visit(i, j, grid));

        return area;
    }
};
