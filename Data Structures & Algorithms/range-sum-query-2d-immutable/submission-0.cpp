class NumMatrix {
   public:
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        prefixSum = vector<vector<int>>(ROWS + 1, vector<int>(COLS + 1, 0));

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] 
                    + prefixSum[i + 1][j] - prefixSum[i][j] 
                    + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSum[row2 + 1][col2 + 1] - prefixSum[row1][col2 + 1]
            - prefixSum[row2 + 1][col1] + prefixSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */