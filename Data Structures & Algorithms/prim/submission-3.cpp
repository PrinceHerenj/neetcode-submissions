class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        // weight dest
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > minHeap;

        vector<bool> visited(n);
        visited[0] = true;
        int visitedCount = 1;

        int totalWeight = 0;

        for (auto& [neighbor_node, neighbor_weight]: adj[0]) {
            minHeap.push({neighbor_weight, neighbor_node});
        }

        while (visitedCount < n && !minHeap.empty()) {
            auto [weight, node] = minHeap.top();
            minHeap.pop();

            if (visited[node]) continue;
            visited[node] = true;
            visitedCount++;

            totalWeight += weight;

            for (auto& [neighbor_node, neighbor_weight]: adj[node]) {
                if (!visited[neighbor_node])
                    minHeap.push({neighbor_weight, neighbor_node});
            }
        }

        return (visitedCount == n) ? totalWeight : -1; 


    }
};

