class MedianFinder {
public:
    priority_queue<int> small_maxh;
    priority_queue<int, vector<int>, greater<int>> large_minh;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small_maxh.push(num);

        if(!small_maxh.empty() and !large_minh.empty() and small_maxh.top() > large_minh.top()) {
            large_minh.push(small_maxh.top());
            small_maxh.pop();
        }

        if (small_maxh.size() > large_minh.size() + 1) {
            large_minh.push(small_maxh.top());
            small_maxh.pop();
        }

        if (small_maxh.size() + 1 < large_minh.size()) {
            small_maxh.push(large_minh.top());
            large_minh.pop();
        }

    }
    
    double findMedian() {
        if (small_maxh.size() > large_minh.size()) return small_maxh.top();
        else if (small_maxh.size() < large_minh.size()) return large_minh.top();

        return (small_maxh.top() + large_minh.top()) / 2.0;
        
    }
};
