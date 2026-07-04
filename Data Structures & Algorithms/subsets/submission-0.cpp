class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        int n = nums.size();
        if (n == 0) return subsets;
        if (n == 1) return {{}, {nums[0]}};

        vector<int> subset;

        dfs(nums, 0, subset, subsets);
        return subsets;
    }

    void dfs(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& subsets){
        if (i >= nums.size()) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, subsets);
        subset.pop_back();
        dfs(nums, i + 1, subset, subsets);
    }
};
