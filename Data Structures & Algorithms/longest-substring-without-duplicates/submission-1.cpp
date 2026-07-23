class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> hash_index;
        int l = 0, res = 0;
        for (int r = 0; r < s.size(); r++) {
            if (hash_index.contains(s[r])) {
                l = max(l, hash_index[s[r]] + 1);
            }
            hash_index[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
