class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p: pre) {
            indegree[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (not indegree[i]) q.push(i);
        }

        int finish = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto& n: adj[node]) {
                indegree[n]--;
                if (!indegree[n]) q.push(n);
            }
            finish++;
        }

        return finish == numCourses;

    }
};
