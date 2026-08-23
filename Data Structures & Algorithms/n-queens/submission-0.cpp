class Solution {
public:
    vector<vector<int>> board;
    vector<vector<string>> res;

    bool checkQueen(int i, int j) {
        int itr = i - 1, jtr;

        // checking in same column
        while (itr >= 0) {
            if (board[itr--][j]) return false;
        }

        itr = i - 1, jtr = j - 1;
        while (itr >= 0 and jtr >= 0) {
            if (board[itr--][jtr--]) return false;
        }

        itr = i - 1, jtr = j + 1;
        while (itr >= 0 and jtr < board.size()) {
            if (board[itr--][jtr++]) return false;
        }

        return true;
    }

    void dfs(int i, vector<string>& curr) {
        if (i == board.size()) {
            res.push_back(curr);
            return;
        }

        for (int col = 0; col < board.size(); col++) {
            if (checkQueen(i, col)) {
                string row(board.size(), '.');
                row[col] = 'Q';
                board[i][col] = 1;
                curr.push_back(row);
                dfs(i + 1, curr);
                board[i][col] = 0;
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, vector<int>(n));

        vector<string> curr;
        dfs(0, curr);

        return res;
    }
};
