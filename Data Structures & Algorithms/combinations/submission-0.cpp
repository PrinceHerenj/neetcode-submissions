class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;

        dfs(1, n, k, res, cur);
        return res;
    }

    void dfs(int i, int n, int k, vector<vector<int>>& res, vector<int> cur) {

        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }

        if (i > n) return;

        cur.push_back(i);
        dfs(i + 1, n, k, res, cur);
        cur.pop_back();
        dfs(i + 1, n, k, res, cur);
    }
};