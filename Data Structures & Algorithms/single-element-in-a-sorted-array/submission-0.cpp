class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((mid - 1 < 0 or nums[mid] != nums[mid - 1])
                and (mid + 1 == nums.size() or nums[mid] != nums[mid + 1])) return nums[mid];
            int leftSide = (mid - 1 >= 0 and nums[mid - 1] == nums[mid]) ? mid - 1 : mid;
            if (leftSide % 2) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};

