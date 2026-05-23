class MinStack {
public:
    vector<pair<int, int>> minst;
    MinStack() {
        minst = {};
    }
    
    void push(int val) {
        if (minst.empty()) minst.emplace_back(val, val);
        else {
            int minval = minst.back().second;
            if (val < minval) minst.emplace_back(val, val);
            else minst.emplace_back(val, minval);
        }
    }
    
    void pop() {
        minst.pop_back();
    }
    
    int top() {
        return minst.back().first;
    }
    
    int getMin() {
        return minst.back().second;
    }
};
