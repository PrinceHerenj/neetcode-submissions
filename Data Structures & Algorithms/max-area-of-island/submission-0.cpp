class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows, cols;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int area = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    area = max(area, dfs(grid, i, j));
                }
            }
        }
        return area;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (min(r, c) < 0 or r == rows or c == cols or grid[r][c] == 0) return 0;

        grid[r][c] = 0;
        int res = 1;
        for (auto& d: directions) {
            res += dfs(grid, r + d[0], c + d[1]);
        }
        return res;
    }
};
