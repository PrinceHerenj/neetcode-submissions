class Solution {
public:
    class UnionFind {
    public:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
        int numComponents;

        UnionFind(int n) {
            for (int i = 1; i <= n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
            numComponents = n;
        }

        int find(int x) {
            int p = parent[x];
            while (p != parent[p]) {
                parent[p] = parent[parent[p]];
                p = parent[p];
            }
            return p;
        }

        bool _union(int x, int y) {
            int p1 = find(x), p2 = find(y);
            if (p1 == p2) return false;

            if (rank[p1] > rank[p2]) parent[p2] = p1;
            else if (rank[p1] < rank[p2]) parent[p1] = p2;
            else {parent[p1] = p2; rank[p2]++;}
            numComponents--;
            return true;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf = UnionFind(n);
        for (auto& edge: edges) {
            if (!uf._union(edge[0], edge[1])) return vector<int>{edge[0], edge[1]};
        }

        return {};
    }
};
