class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto& p: pre) {
            indegree[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finish = 0;
        while (not q.empty()) {
            int node = q.front(); q.pop();
            finish++;
            for (int n: adj[node]) {
                indegree[n]--;
                if (!indegree[n]) q.push(n);
            }
        }

        return finish == numCourses;
    }
};
