class Solution {
public:
    void flipOnHorMid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int j = 0; j < n; j++)
            for (int i = 0; i < n/2; i++)
                swap(matrix[i][j], matrix[n - i - 1][j]);
    }

    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
    }

    void rotate(vector<vector<int>>& matrix) {
        flipOnHorMid(matrix);
        transpose(matrix);
    }
};