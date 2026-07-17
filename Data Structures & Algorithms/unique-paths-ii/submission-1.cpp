class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        if (obstacleGrid[rows-1][cols-1] == 1 or obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> cache;
        cache.resize(rows);
        for (int i = 0; i < rows; i++) {
            cache[i].resize(cols);
        }
        return dfs(0, 0, rows, cols, cache, obstacleGrid);
    }

    int dfs(int r, int c, int rows, int cols, vector<vector<int>>& cache,
            vector<vector<int>>& grid) {
        if (r == rows or c == cols or grid[r][c] == 1) return 0;
        if (cache[r][c] > 0) return cache[r][c];
        if (r == rows - 1 and c == cols - 1) return 1;

        return cache[r][c] =
                   dfs(r + 1, c, rows, cols, cache, grid) + dfs(r, c + 1, rows, cols, cache, grid);
    }
};