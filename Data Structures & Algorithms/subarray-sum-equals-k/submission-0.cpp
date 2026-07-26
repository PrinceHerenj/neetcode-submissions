class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int prefix = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            if (prefixSumCount.contains(prefix - k)) res+= prefixSumCount[prefix - k];
            prefixSumCount[prefix]++;
        }

        return res;
    }
};