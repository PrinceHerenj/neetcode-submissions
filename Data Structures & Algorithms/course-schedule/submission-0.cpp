class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }    

        for (auto& prereq: prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }

        return true;
    }

    bool dfs(int crs) {
        if (visited.contains(crs)) return false;
        if (preMap[crs].empty()) return true;

        visited.insert(crs);
        for (int pre: preMap[crs]) {
            if (!dfs(pre)) return false;
        }
        visited.erase(crs);
        preMap[crs].clear();
        return true;
    }
};
