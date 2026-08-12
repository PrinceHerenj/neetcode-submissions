class Solution {
public:

    vector<bool> visiting;

    vector<int> topologicalSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        visiting.assign(n, false);

        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> res;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!dfs(i, adj, visited, res)) return {};
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(int src, vector<vector<int>>& adj, vector<bool> & visited, vector<int>& res) {
        if (visited[src]) return true;
        if (visiting[src]) return false;

        visiting[src] = true;
        for (auto &neighbor: adj[src]) {
            if (!dfs(neighbor, adj, visited, res)) return false;
        }

        visiting[src] = false;

        visited[src] = true;
        res.push_back(src);

        return true;
    }
};
