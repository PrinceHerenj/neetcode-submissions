class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto& n: nums) {
            count[n]++;
            if (count[n] > nums.size() / 2) return n;
        }

    }
};