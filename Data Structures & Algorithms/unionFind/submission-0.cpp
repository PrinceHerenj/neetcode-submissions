class UnionFind {
private:
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    int numComponents;
public:
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

    bool isSameComponent(int x, int y) {
        return find(x) == find(y);
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {
        if (isSameComponent(x, y)) return false;
        int p1 = find(x), p2 = find(y);

        if (rank[p1] > rank[p2]) parent[p2] = p1;
        else if (rank[p1] < rank[p2]) parent[p1] = p2;
        else {
            parent[p1] = p2;
            rank[p2]++;
        }
        numComponents--;
        return true;
    }

    int getNumComponents() {
        return numComponents;
    }
};
