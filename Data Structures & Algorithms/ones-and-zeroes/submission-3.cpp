class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> arr(strs.size(), vector<int>(2, 0));

        for(int idx = 0; idx < strs.size(); idx++) {
            for (auto &c: strs[idx]) {
                arr[idx][c - '0']++;
            }
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto& p: arr) {
            int zeros = p[0], ones = p[1];
            for (int j = m; j >= zeros; j--)
                for (int k = n; k >= ones; k--) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - zeros][k - ones]);
                }
        }

        return dp[m][n];
        
    }
};