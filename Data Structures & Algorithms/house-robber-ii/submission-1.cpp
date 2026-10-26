class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        dp = vector<int>(n, -1);
        int takingFirst = dfs(0, n - 1, nums);
        dp = vector<int>(n, -1);
        int takingLast = dfs(1, n, nums);
        return max(takingFirst, takingLast);
    }

    int dfs(int i, int end, vector<int>& nums) {
        if (i >= end) return 0;
        if (dp[i] != -1) return dp[i];

        return dp[i] = max(nums[i] + dfs(i + 2, end, nums), dfs(i + 1, end, nums));
    }
};
