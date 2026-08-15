class Solution {
public:
    map<pair<int, int>, int> dp;
    int findTargetSumWays(vector<int>& nums, int target) {
        return dfs(0, 0, nums, target);
    }

    int dfs(int i, int curSum, vector<int>& nums, int target) {
        if (i == nums.size()) return curSum == target;
        if (dp.contains({i, curSum})) return dp[{i, curSum}];

        return dp[{i, curSum}] = dfs(i + 1, curSum + nums[i], nums, target) + dfs(i + 1, curSum - nums[i], nums, target);
    }
};
