class Solution {
public:
    vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        int val = dfs(0, coins, amount);
        return val == 1e9 ? -1 : val;
    }

    int dfs(int i, vector<int>& coins, int amount) {
        if (i == coins.size()) return amount == 0 ? 0 : 1e9;

        if (dp[i][amount] != -1) return dp[i][amount];
        
        // skip current
        dp[i][amount] = dfs(i + 1, coins, amount);

        // include current
        if (amount >= coins[i]) {
            int c = 1 + dfs(i, coins, amount - coins[i]);
            dp[i][amount] = min(dp[i][amount], c);
        }

        return dp[i][amount];
    }
};
