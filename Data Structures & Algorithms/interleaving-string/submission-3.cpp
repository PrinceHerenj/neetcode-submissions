class Solution {
public:
    vector<vector<int>> dp;
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return dfs(0, 0,  s1, s2, s3);
    }

    bool dfs(int i, int j, string& s1, string& s2, string &s3) {
        if (i == s1.size() and j == s2.size()) return true;

        if (dp[i][j] != -1) return dp[i][j];

        if (i < s1.size() and s1[i] == s3[i + j] and dfs(i + 1, j, s1, s2, s3)) return true;
        if (j < s2.size() and s2[j] == s3[i + j] and dfs(i, j + 1, s1, s2, s3)) return true;
        return dp[i][j] = false;
    }
};
