#include <ranges>

class Solution {
public:
    class UnionFind {
    public:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;
        int components;

        UnionFind(int n) {
            components = n;
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
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

            if (rank[p1] > rank[p2]) parent[p2] = p1;
            else if (rank[p2] > rank[p1]) parent[p1] = p2;
            else {
                parent[p1] = p2;
                rank[p2]++;
            }
            components--;
            return true;
        }

    };
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>&b){
            return a[2] < b[2];
        });

        int mstWeight = 0;

        UnionFind uf(n);

        for (auto &edge: edges) {
            int n1 = edge[0], n2 = edge[1], wt = edge[2], i = edge[3];
            if (uf.merge(n1, n2)) {
                mstWeight += wt;
            }
        }

        vector<int> critical, pseudo;

        for (auto &edge: edges) {
            int n1 = edge[0], n2 = edge[1], wt = edge[2], i = edge[3];
            
            // Check if critical
            int weight1 = 0;
            UnionFind uf1(n);
            for (auto &edgen: edges) {
                if (edgen[3] != i && uf1.merge(edgen[0], edgen[1])) {
                    weight1 += edgen[2];
                }
            }
            if (uf1.components > 1 || weight1 > mstWeight) {
                critical.push_back(i);
                continue;
            }

            // Check if pseudo-critical
            int weight2 = wt;
            UnionFind uf2(n);
            uf2.merge(n1, n2);

            for (auto &edgen: edges) {
                if (uf2.merge(edgen[0], edgen[1])) {
                    weight2 += edgen[2];
                }
            }
            if (weight2 == mstWeight) {
                pseudo.push_back(i);
            }
        }

        return {critical, pseudo};
    }
};