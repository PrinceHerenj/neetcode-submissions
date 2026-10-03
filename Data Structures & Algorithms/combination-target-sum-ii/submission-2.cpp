class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> currSet;
        dfs(0, currSet, target, candidates);
        return res;
    }

    void dfs(int i, vector<int>& currSet, int target, vector<int>& candidates) {
        if (target == 0) {
            res.push_back(currSet);
            return;
        }

        if (i >= candidates.size() or target < 0) return;

        currSet.push_back(candidates[i]);
        dfs(i + 1, currSet, target - candidates[i], candidates);

        while (i + 1 < candidates.size() and candidates[i + 1] == candidates[i]) i++;
        currSet.pop_back();
        dfs(i + 1, currSet, target, candidates);
    }
};
