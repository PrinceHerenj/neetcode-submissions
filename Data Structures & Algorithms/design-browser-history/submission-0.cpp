class BrowserHistory {
    struct Node {
        string val;
        Node *next, *prev;
        Node(string val): val(val), next(nullptr), prev(nullptr) {}
    };
public:
    Node *head, *curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
        head = curr;
    }
    
    void visit(string url) {
        Node *newUrl = new Node(url);
        curr->next = newUrl;
        newUrl->prev = curr;
        curr = newUrl;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; i++) {
            if (curr->prev == nullptr) break;
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; i++) {
            if (curr->next == nullptr) break;
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */