class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

    int quickSelect(vector<int>& nums, int l, int r, int k) {
        int pivot = nums[r];
        int pointer = l;

        for (int i = l; i < r; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[pointer]);
                pointer++;
            }
        }
        swap(nums[pointer], nums[r]);

        if (k > pointer) {
            return quickSelect(nums, pointer + 1, r, k);
        } else if (k < pointer) {
            return quickSelect(nums, l, pointer - 1, k);
        } else return nums[pointer];
    }
};
