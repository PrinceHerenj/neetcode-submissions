class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        vector<pair<int, int>> passes(3); // cost - num days
        passes[0] = {costs[0], 1};
        passes[1] = {costs[1], 7};
        passes[2] = {costs[2], 30};
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1e9;
            int j = i;
            for (auto &[cost, duration]: passes) {
                while (j < n && days[j] < days[i] + duration) j++;
                dp[i] = min(dp[i], cost + dp[j]);
            }
        }

        return dp[0];

    }
};