class Solution {
public:
    unordered_map<string,  int> dp;
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, 0, nums, target);
    }

    int dfs(int i, int curSum, vector<int>& nums, int target) {
        if (i == nums.size()) return curSum == target;
        string key = to_string(i) + ',' + to_string(curSum);
        if (dp.contains(key)) return dp[key];

        return dp[key] = dfs(i + 1, curSum + nums[i], nums, target) + dfs(i + 1, curSum - nums[i], nums, target);
    }
};
