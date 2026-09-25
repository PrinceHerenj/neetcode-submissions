class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) return target == nums[0] ? 0 : -1;

        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == nums[mid]) return mid;
            
            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] and target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (target > nums[mid] and target <= nums[r])
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
        }

        return -1;
    }
};
