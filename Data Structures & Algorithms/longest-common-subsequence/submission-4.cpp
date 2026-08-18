class Solution {
public:
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return dfs(0, 0, text1, text2);
    }

    int dfs(int i, int j, string& text1, string& text2) {
        if (i == text1.size() || j == text2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (text1[i] == text2[j])
            return dp[i][j] = 1 + dfs(i + 1, j + 1, text1, text2);

        return dp[i][j] = max(dfs(i + 1, j, text1, text2), dfs(i, j + 1, text1, text2));
    }
};
