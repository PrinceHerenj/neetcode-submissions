class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string e = "";
        dfs(e, 0, 0, n);
        return res;
    }

    void dfs(string& curr, int open, int close, int n) {
        if (open == n and close == n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            dfs(curr, open + 1, close, n);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            dfs(curr, open, close + 1, n);
            curr.pop_back();
        }
    }
};
