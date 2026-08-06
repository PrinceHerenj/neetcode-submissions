class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curSubset;

        sort(nums.begin(), nums.end());
        dfs(0, nums, subsets, curSubset);
        return subsets;
    }

    void dfs(int i, const vector<int>& nums, vector<vector<int>>& subsets, vector<int> curSubset) {
        if (i >= nums.size()) {
            subsets.push_back(curSubset);
            return;
        }

        curSubset.push_back(nums[i]);
        dfs(i + 1, nums, subsets, curSubset);
        curSubset.pop_back();

        while (i + 1 < nums.size() and nums[i] == nums[i + 1]) {
            i++;
        }

        dfs(i + 1, nums, subsets, curSubset);
    }
};
