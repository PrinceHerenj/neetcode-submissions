class Graph {
    unordered_map<int, unordered_set<int>> adj;

    bool dfs(int src, int dst, unordered_set<int>& visited) {
        if (src == dst) return true;
        visited.insert(src);
        for (auto &neighbor: adj[src]) {
            if (!visited.contains(neighbor))
                if (dfs(neighbor, dst, visited))
                    return true;
        }

        return false;
    }

public:
    Graph() {}

    void addEdge(int src, int dst) {
        adj[dst];
        adj[src].insert(dst);
    }

    bool removeEdge(int src, int dst) {
        if (!adj.contains(src) or !adj.contains(dst)) return false;
        return adj[src].erase(dst) > 0;
    }

    bool hasPath(int src, int dst) {
        unordered_set<int> visited;
        return dfs(src, dst, visited);
    }
};
