class MedianFinder {
public:
    priority_queue<int> smallMaxHeap;
    priority_queue<int, vector<int>, greater<>> largeMinHeap;
    MedianFinder() {}
    
    void addNum(int num) {
        smallMaxHeap.push(num);

        if (!smallMaxHeap.empty() and !largeMinHeap.empty() and smallMaxHeap.top() > largeMinHeap.top()) {
            largeMinHeap.push(smallMaxHeap.top());
            smallMaxHeap.pop();
        }

        if (smallMaxHeap.size() > largeMinHeap.size() + 1) {
            largeMinHeap.push(smallMaxHeap.top());
            smallMaxHeap.pop();
        }

        if (smallMaxHeap.size() + 1 < largeMinHeap.size()) {
            smallMaxHeap.push(largeMinHeap.top());
            largeMinHeap.pop();
        }
    }
    
    double findMedian() {
        if (smallMaxHeap.size() > largeMinHeap.size()) return smallMaxHeap.top();
        else if (smallMaxHeap.size() < largeMinHeap.size()) return largeMinHeap.top();
        else {
            return (smallMaxHeap.top() + largeMinHeap.top()) / 2.0;
        }
    }
};
