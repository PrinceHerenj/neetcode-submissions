class Solution {
public:
    int rows, cols;
    void setRowZero(int row, vector<vector<int>>& matrix) {
        for (int i = 0; i < cols; i++) {
            matrix[row][i] = 0;
        }
    }

    void setColZero(int col, vector<vector<int>>& matrix) {
        for (int i = 0; i < rows; i++) {
            matrix[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        vector<bool> czo(cols, false), rzo(rows, false);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    czo[j] = true;
                    rzo[i] = true;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            if (rzo[i]) setRowZero(i, matrix);
        }

        for (int i = 0; i < cols; i++) {
            if (czo[i]) setColZero(i, matrix);
        }
    }
};
