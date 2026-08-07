class Solution {
public:
    unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits == "") return res;
        string cur;
        dfs(0, digits, cur);
        return res;
    }

    void dfs(int i, string digits, string cur) {
        if (i == digits.size()) {
            res.push_back(cur);
            return;
        }
        string toIterate = mp[digits[i]];
        for (auto ch: toIterate) {
            cur += ch;
            dfs(i + 1, digits, cur);
            cur.pop_back();
        }
    }
};
