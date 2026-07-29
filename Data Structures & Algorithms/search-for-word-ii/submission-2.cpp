class Solution {
   public:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    class TrieNode {
       public:
        unordered_map<char, TrieNode*> children;
        string word = "";
    };

    class Trie {
       public:
        TrieNode* root;
        Trie() { root = new TrieNode(); }

        void addWord(string word) {
            TrieNode* curr = root;
            for (auto ch : word) {
                if (!curr->children.contains(ch)) curr->children[ch] = new TrieNode();
                curr = curr->children[ch];
            }
            curr->word = word;
        }
    };

    void dfs(int r, int c, int rows, int cols, TrieNode* node, unordered_set<string>& res,
             vector<vector<char>>& board) {
                if (min(r, c) < 0 || r == rows || c == cols) return;
                char ch = board[r][c];
                if (!node->children.contains(ch)) return;
                node = node->children[ch];
                if (!node->word.empty()) {
                    res.insert(node->word);
                    node->word = "";
                }

                board[r][c] = '#';
                for (auto& d: directions) {
                    int nr = r + d[0], nc = c + d[1];
                    dfs(nr, nc, rows, cols, node, res, board);
                }
                board[r][c] = ch;
                
             }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie wordDict = Trie();
        for (auto& word : words) {
            wordDict.addWord(word);
        }

        unordered_set<string> res;
        TrieNode* curr = wordDict.root;
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) dfs(i, j, rows, cols, curr, res, board);
        return vector<string>(res.begin(), res.end());
    }
};
