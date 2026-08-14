class Solution {
public:
    vector<vector<int>> adj;
    unordered_map<int, unordered_set<int>> prereqMap;
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        adj.resize(numCourses);

        for (auto &p: prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> res;

        for (int i = 0 ; i < numCourses; i++) {
            dfs(i);
        }

        for (auto &q: queries) {
            if (prereqMap[q[1]].contains(q[0])) res.push_back(true);
            else res.push_back(false);
        }

        return res;
    }

    unordered_set<int>& dfs(int crs) {
        if (prereqMap.contains(crs)) return prereqMap[crs];

        prereqMap[crs] = {};

        for (int pre : adj[crs]) {
            auto &cur = dfs(pre);
            prereqMap[crs].insert(cur.begin(), cur.end());
            prereqMap[crs].insert(pre);
        }

        return prereqMap[crs];

    }
};