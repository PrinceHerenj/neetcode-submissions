class Solution {
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2) return false;
        target /= 2;

        dp.resize(nums.size(), vector<int>(target + 1, -1));
        return dfs(0, nums, target);
    }

    bool dfs(int i, vector<int>& nums, int target) {
        if (i == nums.size()) return target == 0;

        if (target < 0) return false;

        if (dp[i][target] != -1) return dp[i][target];

        return dp[i][target] = dfs(i + 1, nums, target) || dfs(i + 1, nums, target - nums[i]);
    }
};
