class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto x: nums) {
            min_heap.push(x);
            if (min_heap.size() > k) min_heap.pop();
        }
    }
    
    int add(int val) {
        min_heap.push(val);
        if (min_heap.size() > k) min_heap.pop();
        return min_heap.top();

    }
};
