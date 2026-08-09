class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < n; i++) {
            adj[i] = vector<pair<int, int>>();
        }

        for (vector<int>& edge: edges) {
            int s = edge[0], d = edge[1], w = edge[2];
            adj[s].push_back({d, w});
        }

        unordered_map<int, int> shortest;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, src});

        while(!minHeap.empty()) {
            auto [weight, node] = minHeap.top();
            minHeap.pop();

            if (shortest.contains(node)) continue;

            shortest[node] = weight;

            for (auto& [neighbor_node, neighbor_weight]: adj[node]){
                if (!shortest.contains(neighbor_node)) {
                    minHeap.push({weight + neighbor_weight, neighbor_node});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!shortest.contains(i)) shortest[i] = -1;
        }

        return shortest;
    }
};
