class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> cache(text1.size(), vector<int>(text2.size()));
        return dfs(0, 0, text1, text2, cache);
    }

    int dfs(int i, int j, string& t1, string& t2, vector<vector<int>>& cache) {
        if (i == t1.size() or j == t2.size()) return 0;
        if (cache[i][j] > 0) return cache[i][j];
        if (t1[i] == t2[j]) return 1 + dfs(i + 1, j + 1, t1, t2, cache);
        return cache[i][j] = max(dfs(i + 1, j, t1, t2, cache), dfs(i, j + 1, t1, t2, cache));
    }
};
