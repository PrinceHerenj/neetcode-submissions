class Solution {
public:
    int rows, cols;
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size(); cols = grid[0].size();
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res += 1;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if (min(r, c) < 0 || r == rows || c == cols || grid[r][c] == '0') return;
        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);

    }
};
