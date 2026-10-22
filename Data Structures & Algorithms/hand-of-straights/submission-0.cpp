class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> count;
        priority_queue<int, vector<int>, greater<>> minHeap;
        for (auto &c: hand) {
            minHeap.push(c);
            count[c]++;
        }

        while (!minHeap.empty()) {
            int min = minHeap.top(); minHeap.pop();
            if (count[min] == 0) continue;
            for (int i = min; i <= min + groupSize - 1; i++) {
                if (count[i] > 0) count[i]--;
                else return false;
            }
        }

        return true;
        
    }
};
