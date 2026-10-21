class Solution {
public:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (auto d: directions) {
                int nr = r + d[0], nc = c + d[1];
                if (min(nr, nc) < 0 or nr == rows or nc == cols or grid[nr][nc] != 2147483647) continue;
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
};