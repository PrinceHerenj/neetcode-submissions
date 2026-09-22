class Solution {
public:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int idx) {
        if (idx == word.size()) return true;
        if (min(i, j) < 0 or i >= board.size() or j >= board[0].size() or board[i][j] != word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = false;
        for (auto d: directions) {
            int ni = i + d[0], nj = j + d[1];
            found |= backtrack(board, word, ni, nj, idx + 1);
        }
        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int, int>> visited;
        string form = "";
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }
};
