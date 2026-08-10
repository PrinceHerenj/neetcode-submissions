class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        int visitedCount = 1;

        // dist src dest
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<> > minHeap;
        for (auto& neighbor: adj[0]) {
            minHeap.push({neighbor.second, 0, neighbor.first});
        }

        int totalWeight = 0;

        while (visitedCount < n && !minHeap.empty()) {
            auto [w1, n1, n2] = minHeap.top();
            minHeap.pop();

            if (visited[n2]) continue;
            visited[n2] = true;
            visitedCount++;

            totalWeight += w1;
            for (auto& [neighbor_node, neighbor_weight]: adj[n2]) {
                if (!visited[neighbor_node]) {
                    minHeap.push({neighbor_weight, n2, neighbor_node});
                }
            }
        }

        return visitedCount == n ? totalWeight : -1;
    }
};