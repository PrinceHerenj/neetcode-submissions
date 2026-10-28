class Solution {
public:
    unordered_map<int, int> dp;
    int numDecodings(string s) {
        dp[s.size()] = 1;
        return dfs(0, s);
    }

    int dfs(int i, string& s) {
        if (dp.contains(i)) return dp[i];
        if (s[i] == '0') return 0;

        int res = dfs(i + 1, s);
        if (i < s.size() - 1) {
            if (s[i] == '1' or s[i] == '2' and s[i + 1] < '7') {
                res += dfs(i + 2, s);
            }
        }

        return dp[i] = res;
    }
};
