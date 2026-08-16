class Solution {
public:
    vector<int> dp;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp.resize(days.size(), -1);
        return dfs(0, days, costs);
    }

    int dfs(int i, vector<int>& days, vector<int>& costs) {
        if (i == days.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int j = i;
        int res = 1e9;
        vector<pair<int, int>> passes(3);
        passes[0] = {costs[0], 1};
        passes[1] = {costs[1], 7};
        passes[2] = {costs[2], 30};

        for (auto &[cost, duration]: passes) {
            while (j < days.size() && days[j] < days[i] + duration) j++;
            res = min(res, cost + dfs(j, days, costs));
        }

        return dp[i] = res;
    }
};