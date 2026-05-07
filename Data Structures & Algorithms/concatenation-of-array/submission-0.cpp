class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int j = 0;
        while (j <= 1) {
            for (int i = 0; i < n; i++) {
                ans.push_back(nums[i]);
            }
            j++;
        }
        return ans;
    }
};