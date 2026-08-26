class TreeMap {
    struct Node {
        int key;
        int val;
        Node* left;
        Node* right;

        Node(int key, int val): key(key), val(val), left(nullptr), right(nullptr) {}
    };
public:
    Node* root;
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        insertHelper(key, val, root);
    }

    void insertHelper(int key, int val, Node*& node) {
        if (node == nullptr) {
            node = new Node(key, val);
            return;
        }
        if (key == node->key) {
            node->val = val;
        } else if (key < node->key) {
            insertHelper(key, val, node->left);
        } else {
            insertHelper(key, val, node->right);
        }
    }

    int get(int key) {
        if (root == nullptr) return -1;
        return getHelper(key, root);
    }

    int getHelper(int key, Node* node) {
        if (!node) return -1;
        if (key < node->key) return getHelper(key, node->left);
        else if (key > node->key) return getHelper(key, node->right);
        else if (key == node->key) return node->val;
        else return -1;
    }

    int getMin() {
        if (!root) return -1;
        Node* node = root;
        while (node->left) {
            node = node->left;
        }

        return node->val;
    }

    int getMax() {
        if (!root) return -1;
        Node* node = root;
        while (node->right) {
            node = node->right;
        }

        return node->val;
    }

    void remove(int key) {
        removeHelper(key, root);
    }

    void removeHelper(int key, Node*& node) {
        if (!node) return;
        if (key < node->key) removeHelper(key, node->left);
        else if (key > node->key) removeHelper(key, node->right);
        else if (key == node->key) {
            if (!node->left and !node->right) {
                delete node;
                node = nullptr;
            } else if (!node->left) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (!node->right) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node* successor = node->right;
                while (successor->left) {
                    successor = successor->left;
                }

                node->key = successor->key;
                node->val = successor->val;

                removeHelper(successor->key, node->right);
            }
        }
        else return;
    }

    std::vector<int> getInorderKeys() {
        vector<int> res;
        inorderHelper(res, root);
        return res;
    }

    void inorderHelper(vector<int>& res, Node* node) {
        if (!node) return;
        inorderHelper(res, node->left);
        res.push_back(node->key);
        inorderHelper(res, node->right);
    }
    
};
