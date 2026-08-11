class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        int res = 0;
        unordered_set<int> visited;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        minHeap.push({0, 0});

        while (visited.size() < n) {
            auto [cost, index] = minHeap.top(); minHeap.pop();

            if (visited.contains(index)) continue;

            res += cost;
            visited.insert(index);
            for (auto &[neighbor_cost, neighbor_index]: adj[index]) {
                if (!visited.contains(neighbor_index)) {
                    minHeap.push({neighbor_cost, neighbor_index});
                }
            }
        }

        return res;
    }
};
