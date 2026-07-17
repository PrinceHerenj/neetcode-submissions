class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int rob1 = nums[0];
        int rob2 = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            // dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
            int temp = rob2;
            rob2 = max(rob2, nums[i] + rob1);
            rob1 = temp;
        }

        return rob2;
    }
};
