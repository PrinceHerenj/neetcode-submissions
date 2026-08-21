class Solution {
public:
    vector<vector<int>> dp;
    int longestPalindromeSubseq(string s) {
        string rv = s;
        reverse(rv.begin(), rv.end());
        dp.resize(s.size(), vector<int>(s.size(), -1));
        return dfs(0, 0, s, rv);
    }

    int dfs(int i, int j, string& s1, string& s2) {
        if (i == s1.size() or j == s2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i] == s2[j]) return dp[i][j] = 1 + dfs(i + 1, j + 1, s1, s2);
        return dp[i][j] = max(dfs(i + 1, j, s1, s2), dfs(i, j + 1, s1, s2));
    }
};