class Solution {
public:
    vector<vector<int>> res;
    unordered_map<int, int> count;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (int& num: nums) {
            count[num]++;
        }

        vector<int> perm;
        dfs(nums, perm);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& perm) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (auto& [num, cnt]: count) {
            if (cnt > 0) {
                perm.push_back(num);
                cnt--;

                dfs(nums, perm);

                perm.pop_back();
                cnt++;
            }
        }
    }

};