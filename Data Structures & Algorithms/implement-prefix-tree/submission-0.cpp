class PrefixTree {
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool word;
    };
public:
    TrieNode *root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for (auto ch: word) {
            if (!curr->children.contains(ch)) curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for (auto ch: word) {
            if (!curr->children.contains(ch)) return false;
            curr = curr->children[ch];
        }
        return curr->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode * curr = root;
        for (auto ch: prefix) {
            if (!curr->children.contains(ch)) return false;
            curr = curr->children[ch];
        }
        return true;
    }
};
