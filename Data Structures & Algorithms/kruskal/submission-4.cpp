class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent, rank;

        UnionFind(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            int p = parent[x];
            while (p != parent[p]) {
                parent[p] = parent[parent[p]];
                p = parent[p];
            }

            return p;
        }

        bool merge(int x, int y) {
            int p1 = find(x), p2 = find(y);
            if (p1 == p2) return false;

            if (rank[p1] < rank[p2]) {
                parent[p1] = p2;
            } else if (rank[p2] < rank[p1]) {
                parent[p2] = p1;
            } else {
                parent[p2] = p1;
                rank[p1]++;
            }

            return true;
        }
    };


    int minimumSpanningTree(vector<vector<int>>& edges, int n) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<> > minHeap;

        for (auto& edge: edges) {
            minHeap.push({edge[2], edge[0], edge[1]});
        }

        UnionFind uf(n);
        int visitedCount = 0;
        int totalWeight = 0;

        while (!minHeap.empty()) {
            auto [wt, n1, n2] = minHeap.top();
            minHeap.pop();

            if (!uf.merge(n1, n2)) continue;

            visitedCount++;
            totalWeight += wt;
        }

        return (visitedCount == n - 1) ? totalWeight : -1;
    }
};
