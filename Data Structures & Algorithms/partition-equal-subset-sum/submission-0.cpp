class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2 != 0) return false;
        target /= 2;

        unordered_set<int> s;
        if (target == nums[0]) return true;
        s.insert(nums[0]);
        s.insert(0);
        for (int i = 1; i < nums.size(); i++) {
            for (auto &el: s) {
                if (el + nums[i] == target) return true;
                s.insert(el + nums[i]);
            }
        }

        return false;
    }

    // void dfs(int i, vector<int>& nums) {

    // }
};
