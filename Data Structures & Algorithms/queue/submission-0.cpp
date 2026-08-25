class Deque {
    struct Node {
        int val;
        Node* next;
        Node* prev;

        Node(int val): val(val), next(nullptr), prev(nullptr) {}
    };
public:
    Node* dummyHead;
    Node* dummyTail;

    Deque() {
        dummyHead = new Node(0);
        dummyTail = new Node(0);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    bool isEmpty() {
        return dummyHead->next == dummyTail;
    }

    void append(int value) {
        Node* node = new Node(value);
        Node* prevNode = dummyTail->prev;

        node->next = dummyTail;
        node->prev = prevNode;

        prevNode->next = node;
        dummyTail->prev = node;
    }

    void appendleft(int value) {
        Node* node = new Node(value);
        Node* nextNode = dummyHead->next;

        node->next = nextNode;
        node->prev = dummyHead;

        dummyHead->next = node;
        nextNode->prev = node;
    }

    int pop() {
        if (isEmpty()) return -1;
        Node* temp = dummyTail->prev;
        Node* prevNode = temp->prev;

        prevNode->next = dummyTail;
        dummyTail->prev = prevNode;
        int res = temp->val;
        delete temp;

        return res;
    }

    int popleft() {
        if (isEmpty()) return -1;
        Node* temp = dummyHead->next;
        Node* nextNode = temp->next;

        nextNode->prev = dummyHead;
        dummyHead->next = nextNode;
        int res = temp->val;
        delete temp;
        return res;
    }
};
