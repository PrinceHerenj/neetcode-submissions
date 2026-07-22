class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curSum = 0;
        for (auto x: nums) {
            curSum = max(0, curSum);
            curSum += x;
            if (curSum > maxSum) maxSum = curSum;
        }

        return maxSum;

    }
};
