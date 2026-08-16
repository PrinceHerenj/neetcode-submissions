class Solution {
public:
    vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        int res = dfs(0, amount, coins);
        return res == 1e9 ? -1 : res;
    }

    int dfs(int i, int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if (i == coins.size()) return 1e9;
        if (dp[i][amount] != -1) return dp[i][amount];

        dp[i][amount] = dfs(i + 1, amount, coins);

        if (amount >= coins[i]) {
            int include = 1 + dfs(i, amount - coins[i], coins);
            dp[i][amount] = min(dp[i][amount], include);
        }

        return dp[i][amount];
        
    }
};
