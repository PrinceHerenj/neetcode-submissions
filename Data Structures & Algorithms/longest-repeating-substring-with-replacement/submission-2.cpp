class Solution {
public:
    int characterReplacement(string s, int k) {
        // vector<int> count(26);
        // count[65 - static_cast<int>(s[0])]++;
        unordered_map<char, int> count;
        int maxCount = 0;
        int l = 0, res = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxCount = max(maxCount, count[s[r]]);
            if (r - l + 1 - maxCount > k) {
                count[s[l++]]--;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};

// 
