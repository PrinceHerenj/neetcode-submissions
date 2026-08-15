class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > totalSum or (totalSum + target) % 2 != 0) return 0;

        int W = (totalSum + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int w = 0; w <= W; w++) {
                dp[i][w] = dp[i - 1][w];

                if (w >= num) {
                    dp[i][w] += dp[i - 1][w - num];
                }
            }
        }

        return dp[n][W];
    }
};
