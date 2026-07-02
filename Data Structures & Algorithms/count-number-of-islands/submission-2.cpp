class Solution {
public:
    typedef pair <int, int> pi;

    void visit(int a, int b, vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue <pi> q;
        q.push({a, b});
        while (not q.empty()) {
            auto c = q.front();
            q.pop();

            int x = c.first, y = c.second;
            grid[x][y] = '2';

            if (x - 1 >= 0 and grid[x - 1][y] == '1') q.push({x - 1, y});
            if (x + 1 < n and grid[x + 1][y] == '1') q.push({x + 1, y});
            if (y - 1 >= 0 and grid[x][y - 1] == '1') q.push({x, y - 1});
            if (y + 1 < m and grid[x][y + 1] == '1') q.push({x, y + 1});
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int comps = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1') {
                    visit(i, j, grid);
                    comps++;
                }

        return comps;
    }
};
