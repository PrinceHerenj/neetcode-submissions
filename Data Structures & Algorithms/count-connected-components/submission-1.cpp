class Solution {
public:
    class UnionFind {
    public:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
        int numComponents;

        UnionFind(int n) {
            for (int i = 0; i < n; i++) {
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
            else {
                parent[p1] = p2;
                rank[p2]++;
            }
            numComponents--;
            return true;
        }

    };
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf = UnionFind(n);
        for (auto& edge: edges) {
            uf._union(edge[0], edge[1]);
        }


        return uf.numComponents;
    }
};
