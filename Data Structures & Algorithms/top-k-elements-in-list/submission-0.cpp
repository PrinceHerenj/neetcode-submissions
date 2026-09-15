class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (auto &i: nums) {
            count[i]++;
        }

        priority_queue<pair<int, int>> pq;
        
        for (auto& [n, c]: count) {
            pq.push({c, n});
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;

    }
};
