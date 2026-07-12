class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (grid[0][0] == 1 or grid[rows - 1][cols - 1] == 1) return -1;
        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        queue<tuple<int, int, int>> q;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        q.push({0, 0, 1});
        visited[0][0] = 1;

        while (not q.empty()) {
            auto [r, c, length] = q.front(); q.pop();
            if (r == rows - 1 and c == cols - 1) return length;
            for (auto& d: directions) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 and nc >= 0 and nr < rows and nc < cols and grid[nr][nc] == 0 and not visited[nr][nc]) {
                    q.push({nr, nc, length + 1});
                    visited[nr][nc] = 1;
                }
            }
        }

        return -1;

    }
};