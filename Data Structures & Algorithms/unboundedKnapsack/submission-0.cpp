class Solution {
public:
    vector<vector<int>> dp;
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        dp.resize(profit.size(), vector<int>(capacity + 1, -1));

        return dfs(0, profit, weight, capacity);
    }

    int dfs(int i, vector<int>& profit, vector<int>& weight, int capacity) {
        if (i == profit.size()) return 0;

        if (dp[i][capacity] != -1) return dp[i][capacity];

        // skip item
        dp[i][capacity] = dfs(i + 1, profit, weight, capacity);
        if (capacity >= weight[i]) {
            int p = profit[i] + dfs(i, profit, weight, capacity - weight[i]);
            dp[i][capacity] = max(dp[i][capacity], p);
        }

        return dp[i][capacity];
    }
};
