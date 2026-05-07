class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxl = 0, l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) l++;
            else {
                if (l > maxl) maxl = l;
                l = 0;
            }
        }
        if (l > maxl) maxl = l;
        return maxl;
    }
};