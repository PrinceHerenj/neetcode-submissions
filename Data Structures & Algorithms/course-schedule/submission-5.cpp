class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
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

        vector<int> res;

        while (!q.empty()) {
            int n = q.front();
            q.pop();

            res.push_back(n);

            for (auto& neighbor: adj[n]) {
                indegree[neighbor]--;
                if (!indegree[neighbor]) q.push(neighbor);
            }
        }

        return res.size() == numCourses ? true : false;
    }
};
