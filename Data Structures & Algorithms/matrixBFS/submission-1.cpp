class Solution {
public:
    int shortestPath(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (grid[0][0] == 1 or grid[rows - 1][cols - 1] == 1) return -1;

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        visited[0][0] = 1;

        queue<pair<int, int>> q;
        q.push({0, 0});

        int length = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); q.pop();
                if (r == rows - 1 and c == cols - 1) return length;
                for (auto d: directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (min(nr, nc) < 0 or nr == rows or nc == cols
                    or visited[nr][nc] or grid[nr][nc] == 1) continue;

                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
            length++;
        }

        return -1;
    }
};
