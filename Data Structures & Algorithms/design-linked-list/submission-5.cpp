class MyLinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
    };

   public:
    Node *head, *tail;
    int size;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* cur = head;
        int i = 0;
        while (i < index) {
            cur = cur->next;
            i++;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        Node* cur = head;
        Node* prev = nullptr;
        int i = 0;
        while (i < index) {
            prev = cur;
            cur = cur->next;
            i++;
        }
        Node* newNode = new Node(val);
        newNode->next = cur;
        prev->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (size == 1) tail = nullptr;
            delete temp;
        } else {
            Node *cur = head, *prev = nullptr;
            for (int i = 0; i < index; i++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            if (index == size - 1) tail = prev;
            delete cur;
        }
        size--;
    }
};