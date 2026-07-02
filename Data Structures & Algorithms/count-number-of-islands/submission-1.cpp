class Solution {
public:
    void visit(int x, int y, vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (x < 0 or x > n - 1 or y < 0 or y > m - 1)
            return;
        if (grid[x][y] != '1')
            return;
        grid[x][y] = '2';

        visit(x - 1, y, grid);
        visit(x + 1, y, grid);
        visit(x, y - 1, grid);
        visit(x, y + 1, grid);
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
