class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void solve(vector<vector<char>>& board) {

        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 or j == 0 or i == m - 1 or j == n - 1) {
                    if (board[i][j] == 'O')
                        dfs(i, j, m, n, board);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }

    }

    void dfs(int i, int j, int rows, int cols, vector<vector<char>>& board) {
        if (min(i, j) < 0 or i == rows or j == cols or board[i][j] == 'X' or board[i][j] == 'T') return;
        board[i][j] = 'T';
        for (auto d: directions) {
            int ni = i + d[0];
            int nj = j + d[1];
            dfs(ni, nj, rows, cols, board);
        }
    }
};
