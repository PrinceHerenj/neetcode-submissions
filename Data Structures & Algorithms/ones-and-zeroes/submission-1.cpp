class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(0, m, n, strs);
    }

    int dfs(int i, int m, int n, vector<string>& strs) {
        if (i == strs.size()) return 0;
        if (dp[i][m][n] != -1) return dp[i][m][n];
        int curM = 0, curN = 0;
        for (auto &c: strs[i]) {
            if (c == '0') curM++;
            else curN++;
        }
        int res = dfs(i + 1, m, n, strs);
        if (m >= curM and n >= curN) res = max(res, 1 + dfs(i + 1, m - curM, n - curN, strs));
        return dp[i][m][n] = res;
    }
};