class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefixSum(nums.size() + 1);

        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        for (int i = 1; i < prefixSum.size(); i++) {
            int temp = prefixSum[prefixSum.size() - 1] - prefixSum[i];
            if (prefixSum[i - 1] == temp) return i - 1;
        }

        return -1;
    }
};