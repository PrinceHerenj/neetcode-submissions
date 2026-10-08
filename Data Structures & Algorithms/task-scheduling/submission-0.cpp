class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxHeap;
        vector<int> freq(26);
        for (auto ch: tasks) {
            freq[ch - 'A']++;
        }

        for (int cnt: freq) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        queue<pair<int, int>> q;
        int time = 0;

        while (!maxHeap.empty() or !q.empty()) {
            time++;
            if (maxHeap.empty()) {
                time = q.front().second;
            } else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();
                if (cnt > 0) q.push({cnt, time + n});
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
        
    }

};
