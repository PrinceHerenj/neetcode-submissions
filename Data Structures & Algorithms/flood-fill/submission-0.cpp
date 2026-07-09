class Solution {
public:
    int rows, cols;
    void dfs(vector<vector<int>> &image, int r, int c, int orig, int color) {
            if (min(r, c) < 0 || r == rows || c == cols || image[r][c] != orig) return;
            image[r][c] = color;
            dfs(image, r + 1, c, orig, color);
            dfs(image, r - 1, c, orig, color);
            dfs(image, r, c + 1, orig, color);
            dfs(image, r, c - 1, orig, color);
        };

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig = image[sr][sc];
        if (orig == color) return image;
        rows = image.size();
        cols = image[0].size();

        dfs(image, sr, sc, orig, color);

        
        return image;
    }
};