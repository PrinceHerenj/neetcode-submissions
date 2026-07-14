class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        for (auto& p: prereq) {
            preMap[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }

        return true;
    }

    bool dfs(int course) {
        if (visited.contains(course)) return false;
        if (preMap[course].empty()) return true;

        visited.insert(course);
        for (auto& p: preMap[course]) {
            if (!dfs(p)) return false;
        }
        visited.erase(course);

        return true;
    }
};
