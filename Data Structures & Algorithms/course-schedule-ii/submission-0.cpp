class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> res;

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for (auto &p: pre) {
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) q.push(i);
        }

        while (!q.empty()) {
            int n = q.front();
            q.pop();

            res.push_back(n);

            for (auto &nei: adj[n]) {
                if (!--indegree[nei]) q.push(nei);
            }
        }

        reverse(res.begin(), res.end());

        return res.size() == numCourses ? res : vector<int> {};
    }
};
