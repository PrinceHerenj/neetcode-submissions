class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        int rows = grid.size(), cols = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }
        if (fresh == 0) return 0;

        int minutes = 0;
        while (!q.empty()) {
            int currSize = q.size();
            for (int i = 0; i < currSize; i++) {
                auto [r, c] = q.front(); q.pop();

                for (auto& d: directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 and nc >= 0 and nr < rows and nc < cols
                    and grid[nr][nc] == 1) {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        fresh--;
                    }
                }
            }
            minutes++;
        }

        if (fresh) return -1;
        return minutes - 1;
    }
};
