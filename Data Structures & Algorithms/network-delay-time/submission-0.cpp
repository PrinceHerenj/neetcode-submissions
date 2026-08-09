class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 1; i <= n; i++) {
            adj[i] = vector<pair<int, int>>();
        }

        for (auto& edge: times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // node shortest_time
        unordered_map<int, int> shortestTime;

        // time node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > minHeap;
        
        minHeap.push({0, k});

        while (!minHeap.empty()) {
            auto [time, node] = minHeap.top();
            minHeap.pop();

            if (shortestTime.contains(node)) continue;

            shortestTime[node] = time;

            for (auto& [neighbor_node, neighbor_time]: adj[node]) {
                if (!shortestTime.contains(neighbor_node)) {
                    minHeap.push({time + neighbor_time, neighbor_node});
                }
            }
        }

        int minTime = 0;

        for (int i = 1; i <= n; i++) {
            if (!shortestTime.contains(i)) return -1;
            minTime = max(minTime,shortestTime[i]);
        }

        return minTime;
    }
};
