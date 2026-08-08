class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return helper(0, nums);
    }

    vector<vector<int>> helper(int i, vector<int>& nums) {
        if (i == nums.size()) {
            return {{}};
        }

        vector<vector<int>> resPerms;
        vector<vector<int>> perms = helper(i + 1, nums);
        for (auto p: perms) {
            for (int j = 0; j <= p.size(); j++) {
                vector<int> pCopy = p;
                pCopy.insert(pCopy.begin() + j, nums[i]);
                resPerms.push_back(pCopy);
            }
        }

        return resPerms;

    }
};
