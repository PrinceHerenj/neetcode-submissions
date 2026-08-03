class MyCalendar {
    struct TreeNode {
        int start, end;
        TreeNode* left, *right;
        TreeNode(int start, int end): start(start), end(end), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    bool insert(TreeNode* node, int start, int end) {
        TreeNode* curr = node;
        while (true) {
            if (start >= curr->end) {
                if (!curr->right) {
                    curr->right = new TreeNode(start, end);
                    return true;
                }
                curr = curr->right;
            } else if (end <= curr->start) {
                if (!curr->left) {
                    curr->left = new TreeNode(start, end);
                    return true;
                }
                curr = curr->left;
            } else {
                return false;
            }
        }
    }
public:
    MyCalendar(): root(nullptr) {}
    
    bool book(int startTime, int endTime) {
        if (!root) {
            root = new TreeNode(startTime, endTime);
            return true;
        }
        return insert(root, startTime, endTime);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */