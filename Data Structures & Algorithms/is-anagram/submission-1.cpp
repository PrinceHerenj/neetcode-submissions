class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> n;
        for (auto x: s) n[x]++;
        for (auto x: t) n[x]--;

        for (auto x: n) {
            if (x.second) return false;
        }

        return true;
    }
};
