class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> cache;
        cache.resize(m);
        for (int i = 0; i < m; i++) {
            cache[i].resize(n);
        }
        return dfs(0, 0, m, n, cache);   
    }

    int dfs(int r, int c, int rows, int cols, vector<vector<int>>& cache) {
        if (r == rows or c == cols) return 0;
        if (cache[r][c] > 0) return cache[r][c];
        if (r == rows - 1 and c == cols - 1) return 1;
        return cache[r][c] = dfs(r + 1, c, rows, cols, cache) + dfs(r, c + 1, rows, cols, cache);
    }
};
