class Solution {
public:
    unordered_map<int, bool> memo;
    bool canJump(vector<int>& nums) {
        return dfs(nums, 0);
    }

    bool dfs(vector<int>& nums, int i) {
        if (memo.contains(i)) return memo[i];
        if (i == nums.size() - 1) return true;

        int end = min((int)nums.size() - 1, i + nums[i]);

        for (int j = i + 1; j <= end; j++) {
            if (dfs(nums, j)) {
                memo[i] = true;
                return true;
            }
        }

        memo[i] = false;
        return false;
    }
};
