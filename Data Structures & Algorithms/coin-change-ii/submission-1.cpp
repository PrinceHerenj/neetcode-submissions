class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        return dfs(0, amount, coins);
    }

    int dfs(int i, int amount, vector<int>& coins) {
        if (i == coins.size()) return amount == 0;
        if (amount == 0) return 1;

        if (dp[i][amount] != -1) return dp[i][amount];

        int res = dfs(i + 1, amount, coins);

        if (amount >= coins[i])
            res += dfs(i, amount - coins[i], coins);

        return dp[i][amount] = res;
        
    }
};
