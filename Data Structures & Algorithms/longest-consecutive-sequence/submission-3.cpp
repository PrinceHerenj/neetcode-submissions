class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for (auto& x: nums) {
            hash.insert(x);
        }

        int maxCount = 0;;

        for (auto& x: hash) {
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
