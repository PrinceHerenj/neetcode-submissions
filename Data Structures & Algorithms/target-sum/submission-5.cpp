class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> dp;
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> nextDp;
            for (auto& [curSum, count]: dp) {
                nextDp[curSum + nums[i]] += count;
                nextDp[curSum - nums[i]] += count;
            }
            dp = nextDp;
        }

        return dp[target];
    }
};
