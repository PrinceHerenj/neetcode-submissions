class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        vector<vector<int>> arr(strs.size(), vector<int>(2, 0));

        for(int idx = 0; idx < strs.size(); idx++) {
            for (auto &c: strs[idx]) {
                arr[idx][c - '0']++;
            }
        }

        for (int i = 1; i <= strs.size(); i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    int count0 = arr[i - 1][0];
                    int count1 = arr[i - 1][1];
                    if (j >= count0 && k >= count1) {
                        dp[i][j][k] = max(dp[i][j][k], 1 + dp[i - 1][j - count0][k - count1]);
                    }
                }
            }
        }

        return dp[strs.size()][m][n];
        
    }
};