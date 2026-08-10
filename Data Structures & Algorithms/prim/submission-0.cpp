class Solution {
public:
    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        unordered_set<int> visited;
        visited.insert(0);

        // dist src dest
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<> > minHeap;
        for (auto& neighbor: adj[0]) {
            minHeap.push({neighbor.second, 0, neighbor.first});
        }

        int totalWeight = 0;

        while (visited.size() < n && !minHeap.empty()) {
            auto [w1, n1, n2] = minHeap.top();
            minHeap.pop();

            if (visited.contains(n2)) continue;

            totalWeight += w1;
            visited.insert(n2);
            for (auto& [neighbor_node, neighbor_weight]: adj[n2]) {
                if (!visited.contains(neighbor_node)) {
                    minHeap.push({neighbor_weight, n2, neighbor_node});
                }
            }
        }

        return visited.size() == n ? totalWeight : -1;

        

    }
};

