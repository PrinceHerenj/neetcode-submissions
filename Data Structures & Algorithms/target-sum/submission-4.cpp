class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (auto& [curSum, count]: dp[i]) {
                dp[i + 1][curSum + nums[i]] += count;
                dp[i + 1][curSum - nums[i]] += count;
            }
        }

        return dp[n][target];
    }
};
