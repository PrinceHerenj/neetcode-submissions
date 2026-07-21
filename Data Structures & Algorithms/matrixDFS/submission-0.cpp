class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int countPaths(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        return dfs(0, 0, rows, cols, grid);
    }

    int dfs(int r, int c, int rows, int cols, vector<vector<int>>& grid) {
        if (min(r, c) < 0 || r == rows || c == cols || grid[r][c] == 1) return 0;
        if (r == rows - 1 and c == cols - 1) return 1;

        grid[r][c] = 1;
        int cnt = 0;
        for (auto x: directions) {
            int nr = r + x[0], nc = c + x[1];
            cnt += dfs(nr, nc, rows, cols, grid);
        }
        grid[r][c] = 0;
        return cnt;
    }
};
