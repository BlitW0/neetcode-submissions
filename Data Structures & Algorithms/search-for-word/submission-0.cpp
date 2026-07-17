class Solution {
public:
    const vector <pair <int, int> > dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool find(int idx, int r, int c, vector<vector<char>>& board, string& word) {
        if (idx == word.size())
            return true;
        
        bool valid = r >= 0 and r < board.size() and c >= 0 and c < board[0].size();
        if (not valid) return false;

        if (board[r][c] == '#' or word[idx] != board[r][c])
            return false;

        bool ret = false;
        char orig = board[r][c];
        for (auto& [dr, dc] : dir) {
            int nr = r + dr, nc = c + dc;

            board[r][c] = '#';
            ret = ret or find(idx + 1, nr, nc, board, word);
            board[r][c] = orig;
        }
        return ret;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;

        int n = board.size(), m = board[0].size();
        bool ret = false;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == word[0])
                    ret = ret or find(0, i, j, board, word);

        return ret;
    }
};