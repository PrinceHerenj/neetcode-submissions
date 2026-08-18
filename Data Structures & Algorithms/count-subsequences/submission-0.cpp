class Solution {
public:
    vector<vector<int>> dp;
    int numDistinct(string s, string t) {
        dp.resize(s.size() + 1, vector<int>(t.size() + 1, -1));
        return dfs(0, 0, s, t);
    }

    int dfs(int i, int j, string& s, string& t) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (s[i] == t[j]) 
            dp[i][j] = dfs(i + 1, j + 1, s, t) + dfs(i + 1, j, s, t);
        else dp[i][j] = dfs(i + 1, j, s, t);
        return dp[i][j];
    }
};
