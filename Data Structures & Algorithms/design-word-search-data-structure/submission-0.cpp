class WordDictionary {
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool word;
    };
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (auto ch: word) {
            if (!curr->children.contains(ch)) curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        return searchInNode(word, 0, curr);
    }

    bool searchInNode(string word, int index, TrieNode* node) {
        if (index == word.size()) return node->word;
        if (word[index] == '.') {
            bool res = false;
            for (auto child: node->children) {
                res |= searchInNode(word, index + 1, child.second);
            }
            return res;
        } else {
            char ch = word[index];
            if (!node->children.contains(ch)) return false;
            return searchInNode(word, index + 1, node->children[ch]);
        }
    }
};
