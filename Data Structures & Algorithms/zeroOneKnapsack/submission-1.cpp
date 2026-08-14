class Solution {
public:
    vector<vector<int>> cache;
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        cache.assign(profit.size(), vector<int>(capacity + 1, -1));
        return dfs(0, profit, weight, capacity);
    }

    int dfs(int i, vector<int> &profit, vector<int> &weight, int capacity) {
        if (i == profit.size()) return 0;
        if (cache[i][capacity] != -1) return cache[i][capacity];
        
        // Skipping Item
        cache[i][capacity] = dfs(i + 1, profit, weight, capacity);

        // Adding Item
        int newCap = capacity - weight[i];
        if (newCap >= 0) {
            int p = profit[i] + dfs(i + 1, profit, weight, newCap);
            cache[i][capacity] = max(p, cache[i][capacity]);
        }

        return cache[i][capacity];
        
    }
};
