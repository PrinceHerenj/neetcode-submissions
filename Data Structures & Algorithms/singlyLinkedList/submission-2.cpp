class LinkedList {
    struct Node {
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
    };
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* curr = head;
        int i = 0;
        while (curr) {
            if (i == index) return curr->val;
            curr = curr->next;
            i++;
        }
        return -1;
    }

    void insertHead(int val) {
        Node* node = new Node(val);
        node->next = head;
        head = node;
    }
    
    void insertTail(int val) {
        if (!head) {
            head = new Node(val);
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }

        curr->next = new Node(val);
    }

    bool remove(int index) {
        if (index < 0 || !head) return false;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

        Node* curr = head;
        for (int i = 0; curr && i < index - 1; i++) {
            curr = curr->next;
        }

        if (!curr || !curr->next) return false;

        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return true;
    }

    vector<int> getValues() {
        Node* curr = head;
        vector<int> res;
        while (curr) {
            res.push_back(curr->val);
            curr = curr->next;
        }

        return res;
    }
};
