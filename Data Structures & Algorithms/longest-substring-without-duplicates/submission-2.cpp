class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> hash;
        int l = 0, res = 0;
        for (int r = 0; r < s.size(); r++) {
            while (hash.contains(s[r])) {
                hash.erase(s[l++]);
            }
            hash.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
