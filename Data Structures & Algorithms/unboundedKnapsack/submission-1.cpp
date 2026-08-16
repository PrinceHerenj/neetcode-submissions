class Solution {
public:
    vector<vector<int>> dp;
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        dp.resize(profit.size(), vector<int>(capacity + 1, -1));

        return dfs(0, capacity, profit, weight);
    }

    int dfs(int i, int capacity, vector<int>& profit, vector<int>& weight) {
        if (i == profit.size()) return 0;

        if (dp[i][capacity] != -1) return dp[i][capacity];

        dp[i][capacity] = dfs(i + 1, capacity, profit, weight);
        if (capacity >= weight[i]) {
            int p = profit[i] + dfs(i, capacity - weight[i], profit, weight);
            dp[i][capacity] = max(dp[i][capacity], p);
        }

        return dp[i][capacity];
    }
};
