class Solution {
public:
    vector<vector<int>> dp;
    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return dfs(0, s.size() - 1, s);
    }


    int dfs(int i, int j, string& s) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j]) {
            return dp[i][j] = 2 + dfs(i + 1, j - 1, s);
        }
        else {
            return dp[i][j] = max(dfs(i + 1, j, s), dfs(i, j - 1, s));
        }
    }
};