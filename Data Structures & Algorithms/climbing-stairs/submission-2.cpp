class Solution {
public:
    vector<int> hash;
    int climbStairs(int n) {
        hash.resize(n, -1);
        return dfs(n, 0);
    }

    int dfs(int n, int i) {
        if (i >= n) return i == n;
        if (hash[i] != -1) return hash[i];
        hash[i] = dfs(n, i + 1) + dfs(n, i + 2);
        return hash[i];
    }
};
