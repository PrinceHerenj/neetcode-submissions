class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (hash.contains(target - nums[i])) {
                if (i == hash[target - nums[i]]) continue;
                return {i, hash[target - nums[i]]};
            }
        }
        return {};
    }
};
