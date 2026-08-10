class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> maxProbs(n, INT_MIN);
        maxProbs[start_node] = 1;

        priority_queue<pair<double, int>> maxHeap;
        maxHeap.push({1, start_node});

        while (!maxHeap.empty()) {
            auto [prob, node] = maxHeap.top();
            maxHeap.pop();

            if (prob < maxProbs[node]) continue;
            maxProbs[node] = prob;

            for (auto& [neighbor_node, neighbor_prob]: adj[node]) {
                if (prob * neighbor_prob > maxProbs[neighbor_node]) {
                    maxProbs[neighbor_node] = prob * neighbor_prob;
                    maxHeap.push({maxProbs[neighbor_node], neighbor_node});
                }
            }
        }

        if (maxProbs[end_node] == INT_MIN) return 0;
        return maxProbs[end_node];

        
    }
};