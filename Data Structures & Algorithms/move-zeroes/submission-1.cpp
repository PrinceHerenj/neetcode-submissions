class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lp = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) swap(nums[lp++], nums[i]);
        }
    }
};