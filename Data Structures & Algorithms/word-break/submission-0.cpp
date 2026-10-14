class Solution {
public:
    unordered_map<int, bool> memo;
    bool wordBreak(string s, vector<string>& wordDict) {
        memo[s.size()] = true;
        return dfs(s, wordDict, 0);
    }

    bool dfs(string& s, vector<string>& wordDict, int i) {
        if (memo.contains(i)) return memo[i];

        for (const string& w: wordDict) {
            if (i + w.size() <= s.size() && s.substr(i, w.size()) == w) {
                if (dfs(s, wordDict, i + w.size())) {
                    return memo[i] = true;
                }
            }
        }

        memo[i] = false;
        return false;
    }
};
