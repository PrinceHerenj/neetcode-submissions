class Solution {
public:
    int minDistance(string word1, string word2) {
        if (!word1.size()) return word2.size();
        if (!word2.size()) return word1.size();
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        int itr = 0;
        for (int j = word2.size(); j >= 0; j--) {
            dp[word1.size()][j] = itr++;
        }
         itr = 1;
        for (int i = word1.size() - 1; i >= 0; i--) {
            dp[i][word2.size()] = itr++;
        }

        for (int i = word1.size() - 1; i >= 0; i--) {
            for (int j = word2.size() - 1; j >= 0; j--) {
                if (word1[i] == word2[j]) dp[i][j] = dp[i + 1][j + 1];
                else dp[i][j] = 1 + min({
                    dp[i + 1][j],
                    dp[i][j + 1],
                    dp[i + 1][j + 1]
                });
            }
        }

        return dp[0][0];
    }
};
