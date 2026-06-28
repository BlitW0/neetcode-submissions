class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector <vector <bool> > &vis, int x, int y) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() || vis[x][y] || grid[x][y] != '1') return;
        vis[x][y] = 1;
        dfs(grid, vis, x + 1, y); dfs(grid, vis, x, y + 1);
        dfs(grid, vis, x - 1, y); dfs(grid, vis, x, y - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector <vector <bool> > vis (n, vector <bool> (m, 0));

        int islands = 0;
        for (int x = 0; x < n; x++)
            for (int y = 0; y < m; y++)
                if (!vis[x][y] && grid[x][y] == '1') {
                    dfs(grid, vis, x, y);
                    islands++;
                }
        
        return islands;
    }
};