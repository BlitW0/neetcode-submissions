class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector <vector <int> > ttr(n, vector <int> (m, INT_MAX));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                    dfs(grid, ttr, i, j, 0);
        
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    if (ttr[i][j] == INT_MAX)
                        return ans = -1;
                    ans = max(ans, ttr[i][j]);
                }
        
        return ans;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& ttr, int x, int y, int dist) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size())
            return;
        if (!grid[x][y] || (ttr[x][y] != INT_MAX && ttr[x][y] <= dist))
            return;

        ttr[x][y] = dist;
        dfs(grid, ttr, x - 1, y, dist + 1);
        dfs(grid, ttr, x + 1, y, dist + 1);
        dfs(grid, ttr, x, y - 1, dist + 1);
        dfs(grid, ttr, x, y + 1, dist + 1);
    }
};