class Solution {
public:
    class BoardCheck {
        vector <int> num;
        int size;
    
    public:
        BoardCheck(int sz) {
            size = sz;
            num = vector <int> (sz + 1, 0);
        }

        void update(char c) {
            if (c >= '0' and c <= char('0' + size))
                num[c - '0']++;
        }

        void clear() { fill(num.begin(), num.end(), 0); }

        bool check() {
            for (int i = 1; i <= size; i++)
                if (num[i] > 1)
                    return false;
            return true;
        }

        void print() {
            for (int i = 1; i <= size; i++)
                if (num[i])
                    cout << i << '(' << num[i] << ");";
            cout << '\n';
        }
    };

    bool check_box(int x, int y, BoardCheck& bc, vector<vector<char>>& board) {
        bc.clear();
        for (int i = x; i < x + 3; i++)
            for (int j = y; j < y + 3; j++)
                bc.update(board[i][j]);
        return bc.check();
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        BoardCheck bc(3*3);

        // rows
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                bc.update(board[i][j]);
            if (not bc.check())
                return false;
            bc.clear();
        }

        // columns
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++)
                bc.update(board[i][j]);
            if (not bc.check())
                return false;
            bc.clear();
        }

        // boxes
        for (int i = 0; i < 9; i += 3)
            for (int j = 0; j < 9; j += 3)
                if (not check_box(i, j, bc, board))
                    return false;

        return true;
    }
};
