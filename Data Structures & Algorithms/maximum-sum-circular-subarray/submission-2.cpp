class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0], minSum = nums[0];
        int curMax = 0, curMin = 0;
        int totalSum = 0;

        for (auto x: nums) {
            curMax = max(curMax + x, x);
            curMin = min(curMin + x, x);
            maxSum = max(curMax, maxSum);
            minSum = min(curMin, minSum);
            totalSum += x;
        }

        if (maxSum < 0) return maxSum;
        return max(totalSum - minSum, maxSum);
    }
};