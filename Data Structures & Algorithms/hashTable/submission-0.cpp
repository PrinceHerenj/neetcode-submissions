class HashTable {
    struct Node {
        int key;
        int val;
        Node* next;

        Node(int key, int val): key(key), val(val), next(nullptr) {}
    };
    
    int capacity, size;
    vector<Node*> table;

    int hashFunction(int key) {
        return key % capacity;
    }
public:
    HashTable(int capacity): capacity(capacity), size(0) {
        table.resize(capacity, nullptr);
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        Node* node = table[index];

        if (!node) {
            table[index] = new Node(key, value);
            size++;
        } else {
            Node* prev = nullptr;
            while (node) {
                if (node->key == key) {
                    node->val = value;
                    return;
                }
                prev = node;
                node = node->next;
            }
            prev->next = new Node(key, value);
            size++;
        }

        if ((float) size / capacity >= 0.5) resize();
    }

    int get(int key) {
        int index = hashFunction(key);
        Node* node = table[index];

        while (node) {
            if (node->key == key) {
                return node->val;
            }
            node = node->next;
        }

        return -1;
    }

    bool remove(int key) {
        int index = hashFunction(key);
        Node* node = table[index];
        Node* prev = nullptr;
        while (node) {
            if (node->key == key) {
                if (prev) {
                    prev->next = node->next;
                } else {
                    table[index] = node->next;
                }
                delete node;
                size--;
                return true;
            }
            prev = node;
            node = node->next;
        }
        return false;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void resize() {
        int newCapacity = capacity * 2;
        vector<Node*> newTable(newCapacity, nullptr);

        for (Node* node: table) {
            while (node) {

                int index = node->key % newCapacity;
                if (!newTable[index]) {
                    newTable[index] = new Node(node->key, node->val);
                } else {
                    Node* newNode = newTable[index];
                    while (newNode->next) {
                        newNode = newNode->next;
                    }
                    newNode->next = new Node(node->key, node->val);
                }
                Node* toDelete = node;
                node = node->next;
                delete toDelete;
            }
        }
        capacity = newCapacity;
        table = newTable;
    }
};
