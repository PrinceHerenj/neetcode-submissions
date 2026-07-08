class LRUCache {
public:

    struct Node {
        int key, val;
        Node* prev;
        Node* next;

        Node(int key, int val): key(key), val(val), prev(nullptr), next(nullptr) {}
    };
    unordered_map<int, Node*> hash;


    Node* head;
    Node* tail;
    int capacity = 0;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtTail(Node* node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    
    
    int get(int key) {
        if (!hash.count(key)) return -1;
        Node* curr = hash[key];
        removeNode(curr);
        insertAtTail(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        if (hash.count(key)) {
            Node* curr = hash[key];
            curr->val = value;
            removeNode(curr);
            insertAtTail(curr);
            return;
        }

        if (hash.size() == capacity) {
            Node* lru = head->next;
            hash.erase(lru->key);
            removeNode(lru);
            delete lru;
        }

        Node* newNode = new Node(key, value);
        hash[key] = newNode;
        insertAtTail(newNode);
    }
};
