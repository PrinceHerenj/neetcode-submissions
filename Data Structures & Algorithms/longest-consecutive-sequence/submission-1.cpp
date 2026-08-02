class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) return 0;
        unordered_set<int> hash;
        for (auto& x: nums) {
            hash.insert(x);
        }

        int maxCount = INT_MIN;;

        for (auto& x: nums) {
            if (hash.contains(x - 1)) continue;
            else {
                int temp = x;
                int count = 1;
                while (hash.contains(++temp)) count++;
                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};
