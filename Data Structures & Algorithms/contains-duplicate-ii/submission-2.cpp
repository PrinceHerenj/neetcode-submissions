class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (r - l > k) {
                hash.erase(nums[l]);
                l++;
            }
            if (hash.contains(nums[r])) return true;
            hash.insert(nums[r]);
        }  
        return false;
    }
};