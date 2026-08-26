class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 and nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int target = nums[i] + nums[l] + nums[r];
                if (target > 0) r--;
                else if (target < 0) l++;
                else {
                    res.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < r and nums[l] == nums[l - 1]) l++;
                }
            }
        }

        return res;
    }
};
