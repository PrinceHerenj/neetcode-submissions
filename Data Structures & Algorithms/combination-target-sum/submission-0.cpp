class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;

        vector<int> combination;
        dfs(0, nums, target, combination, res);
        return res;
    }

    void dfs(int start, vector<int>& nums, int target, vector<int>& combination, vector<vector<int>>& res) {
        if (target < 0) return;

        if (target == 0) {
            res.push_back(combination);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            combination.push_back(nums[i]);
            dfs(i, nums, target - nums[i], combination, res);
            combination.pop_back();
        }
    }
};
