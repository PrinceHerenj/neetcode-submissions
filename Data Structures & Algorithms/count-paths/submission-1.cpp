class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prevRow(n);

        for (int r = 0; r < m; r++) {
            vector<int> curRow(n);
            curRow[0] = 1;
            for (int j = 1; j < n; j++) {
                curRow[j] = curRow[j - 1] + prevRow[j];
            }
            prevRow = curRow;
        }

        return prevRow[n - 1];
    }
};
