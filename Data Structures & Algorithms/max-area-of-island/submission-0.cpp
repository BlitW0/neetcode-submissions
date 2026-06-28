class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector <vector <bool> > &vis, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || vis[x][y] || !grid[x][y]) return 0;
        vis[x][y] = 1;
        int ret = 1;
        ret += dfs(grid, vis, x + 1, y); 
        ret += dfs(grid, vis, x, y + 1);
        ret += dfs(grid, vis, x - 1, y); 
        ret += dfs(grid, vis, x, y - 1);
        return ret;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector <vector <bool> > vis (n, vector <bool> (m, 0));
        
        int ans = 0;
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
                if (!vis[x][y] && grid[x][y])
                    ans = max(ans, dfs(grid, vis, x, y));
        
        return ans;
    }
};