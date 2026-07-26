class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> leftSum(nums.size()), rightSum(nums.size());
        leftSum[0] = nums[0];
        rightSum[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); i++) {
            leftSum[i] = leftSum[i - 1] + nums[i];
        }

        for (int i = nums.size() - 2; i >= 0; i--) {
            rightSum[i] = rightSum[i + 1] + nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (leftSum[i] == rightSum[i]) return i;
        }

        return -1;
    }
};