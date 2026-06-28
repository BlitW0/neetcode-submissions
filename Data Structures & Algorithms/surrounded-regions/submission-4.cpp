class Solution {
public:

    vector <vector <bool> > vis;

    void visit(vector<vector<char>>& board, int x, int y) {
        int m = board.size(), n = board[0].size();

        if (x < 0 or x > m - 1 or y < 0 or y > n - 1)
            return;
        if (board[x][y] == 'X' or vis[x][y])
            return;
        vis[x][y] = true;

        visit(board, x + 1, y);
        visit(board, x - 1, y);
        visit(board, x, y + 1);
        visit(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vis = vector <vector <bool> >(m, vector <bool> (n));

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' and not vis[i][0])
                visit(board, i, 0);
            if (board[i][n - 1] == 'O' and not vis[i][n - 1])
                visit(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' and not vis[0][j])
                visit(board, 0, j);
            if (board[m - 1][j] == 'O' and not vis[m - 1][j])
                visit(board, m - 1, j);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O' and not vis[i][j])
                    board[i][j] = 'X';
    }
};
