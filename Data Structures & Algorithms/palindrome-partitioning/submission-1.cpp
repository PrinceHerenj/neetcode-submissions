class Solution {
public:
    vector<vector<string>> res;
    vector<string> part;

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return res;
    }

    void dfs(int i, string& s) {
        if (i >= s.size()) {
            res.push_back(part);
            return;
        }

        for (int j = i; j < s.size(); j++) {
            if (isPali(s, i, j)) {
                part.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s);
                part.pop_back();
            }
        }
    }

    bool isPali(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
