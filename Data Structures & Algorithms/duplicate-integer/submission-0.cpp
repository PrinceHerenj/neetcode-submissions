class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto x: nums) {
            hash[x]++;
            if (hash[x] == 2) return true;
        }
        return false;
    }
};