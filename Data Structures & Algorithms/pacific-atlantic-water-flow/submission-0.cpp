class Solution {
public:
    vector<vector<bool>> pacific;
    vector<vector<bool>> atlantic;
    int rows, cols;

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(int r, int c, vector<vector<bool>> &visit, int prevHeight, vector<vector<int>>& heights) {
        if (min(r, c) < 0 or r == rows or c == cols) return;
        if (visit[r][c] or heights[r][c] < prevHeight) return;

        visit[r][c] = true;
        for (auto &d: directions) {
            dfs(r + d[0], c + d[1], visit, heights[r][c], heights);
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        pacific.assign(rows, vector<bool>(cols, false));
        atlantic.assign(rows, vector<bool>(cols, false));

        for (int c = 0; c < cols; c++) {
            dfs(0, c, pacific, heights[0][c], heights);
            dfs(rows - 1, c, atlantic, heights[rows - 1][c], heights);
        }

        for (int r = 0; r < rows; r++) {
            dfs(r, 0, pacific, heights[r][0], heights);
            dfs(r, cols - 1, atlantic, heights[r][cols - 1], heights);
        }

        vector<vector<int>> res;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] and atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};
