class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = nums[i] + prefixSum[i];
        }
    }
    
    int sumRange(int left, int right) {
        int prefixRight = prefixSum[right + 1];
        int prefixLeft = prefixSum[left];
        return prefixRight - prefixLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */