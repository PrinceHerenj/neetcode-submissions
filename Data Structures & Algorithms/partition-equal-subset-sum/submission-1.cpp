class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2) return false;

        unordered_set<int> dp;
        dp.insert(0);
        target /= 2;

        for (int i = nums.size() - 1; i >= 0; i--) {
            unordered_set<int> nextDP;
            for (int t: dp) {
                if (t + nums[i] == target) return true;
                nextDP.insert(t + nums[i]);
                nextDP.insert(t);
            }
            dp = nextDP;
        }

        return false;
    }
};
