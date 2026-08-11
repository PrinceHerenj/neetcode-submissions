class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        vector<vector<pair<int, int>>> adj(n);

        // src = {dst, dist}
        for (auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // distance src dest
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > minHeap;
        unordered_map<int, int> shortest;

        for (int i = 0; i < n; i++) {
            shortest[i] = INT_MAX;
        }

        shortest[src] = 0;

        minHeap.push({0, src});

        while (!minHeap.empty()) {
            auto [dist, node] = minHeap.top();
            minHeap.pop();

            if (dist > shortest[node]) continue;
            shortest[node] = dist;

            for (auto & [neighbor_node, neighbor_dist]: adj[node]) {
                if (dist + neighbor_dist < shortest[neighbor_node]) {
                    shortest[neighbor_node] = dist + neighbor_dist;
                    minHeap.push({shortest[neighbor_node], neighbor_node});
                }
            }
        }

        for (int i = 0; i < shortest.size(); i++) {
            if (shortest[i] == INT_MAX) shortest[i] = -1;
        }
        

        return shortest;
    }
};
