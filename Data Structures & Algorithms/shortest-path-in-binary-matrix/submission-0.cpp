class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1 or grid[grid.size() - 1][grid[0].size() - 1] == 1) return -1;
        return bfs(grid);
    }

    int bfs(vector<vector<int>>& grid) {
        int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1},  {0, -1}, {0, 1},  {1, -1}, {1, 0}, {1, 1}};
        int rows = grid.size(), cols = grid[0].size();

        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        int length = 1;
        
        while (not q.empty()) {
            int currSize = q.size();
            for (int i = 0; i < currSize; i++) {
                auto [r, c] = q.front(); q.pop();
                if (r == rows - 1 and c == cols - 1) return length;

                for (auto& d: directions) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nc >= 0 && nr < rows && nc < cols 
                    && grid[nr][nc] == 0 && !visit[nr][nc]) {
                        q.push({nr, nc});
                        visit[nr][nc] = true;
                    }
                }
            }
            length++;
        }

        return -1;
    }
};