class Solution {
public:
    unordered_map<int, int> hash;
    int climbStairs(int n) {
        return dfs(n, 0);
    }

    int dfs(int n, int i) {
        if (i >= n) return i == n;
        if (hash[i]) return hash[i];
        hash[i] = dfs(n, i + 1) + dfs(n, i + 2);
        return hash[i];
    }
};
