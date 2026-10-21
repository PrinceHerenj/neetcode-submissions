class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 0) return true;
        if (edges.size() > n - 1) return false;

        vector<vector<int>> adj(n);

        for (auto& edge: edges) {
            int s = edge[0], d = edge[1];
            adj[s].push_back(d);
            adj[d].push_back(s);
        }

        unordered_set<int> visit;

        if (!dfs(0, -1, visit, adj)) return false;
        return visit.size() == n;
    }

    bool dfs(int i, int prev, unordered_set<int>& visit, vector<vector<int>>& adj) {
        if (visit.contains(i)) return false;

        visit.insert(i);

        for (auto& nei: adj[i]) {
            if (nei == prev) continue;

            if (!dfs(nei, i, visit, adj)) return false;
        }

        return true;
    }
};
