class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string res;
        while (i < word1.size() and j < word2.size()) {
            if (i <= j) res.push_back(word1[i++]);
            else res.push_back(word2[j++]);
        }

        while (i < word1.size()) res.push_back(word1[i++]);
        while (j < word2.size()) res.push_back(word2[j++]);

        return res;
    }
};