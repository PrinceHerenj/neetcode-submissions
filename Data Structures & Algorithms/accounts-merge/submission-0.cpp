class Solution {
public:
    class UnionFind {
    public:
        unordered_map<int, int> parent;
        unordered_map<int, int> rank;

        UnionFind(int n) {
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

        bool _union(int x, int y) {
            int p1 = find(x), p2 = find(y);
            if (p1 == p2) return false;

            if (rank[p1] > rank[p2]) parent[p2] = p1;
            else if (rank[p1] < rank[p2]) parent[p1] = p2;
            else {
                parent[p1] = p2;
                rank[p2]++;
            }

            return true;
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf = UnionFind(accounts.size());
        unordered_map<string, int> emailToAcc;

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (!emailToAcc.contains(accounts[i][j])) {
                    emailToAcc[accounts[i][j]] = i;
                } else {
                    uf._union(i, emailToAcc[accounts[i][j]]);
                }
            }
        }

        

        map<int, vector<string>> emailGroup;
        for(auto &[email, accId]: emailToAcc) {
            int leader = uf.find(accId);
            emailGroup[leader].push_back(email);
        }

        vector<vector<string>> res;
        for (auto &[accId, emails]: emailGroup) {
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[accId][0]);
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(merged);
        }
        return res;
    }
};