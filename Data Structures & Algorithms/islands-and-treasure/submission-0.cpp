class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 0)
                    dfs(grid, i, j, 0);
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int dist) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
            return;
        if (grid[x][y] != 0 && dist >= grid[x][y])
            return;

        grid[x][y] = min(grid[x][y], dist);
        dfs(grid, x - 1, y, dist + 1);
        dfs(grid, x + 1, y, dist + 1);
        dfs(grid, x, y - 1, dist + 1);
        dfs(grid, x, y + 1, dist + 1);
    }
};
