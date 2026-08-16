class Solution {
public:
    vector<vector<int>> dp;
    int stoneSum;
    int lastStoneWeightII(vector<int>& stones) {
        stoneSum = accumulate(stones.begin(), stones.end(), 0);
        int target = ceil(stoneSum / 2);
        dp.resize(stones.size(), vector<int>(target + 1, -1));
        return dfs(0, 0, stones, target);
    }

    int dfs(int i, int curSum, vector<int>& stones, int target) {
        if (curSum >= target || i == stones.size())
            return abs(curSum - (stoneSum - curSum));
        
        if (dp[i][curSum] != -1) return dp[i][curSum];

        return dp[i][curSum] = min(dfs(i + 1, curSum, stones, target), dfs(i + 1, curSum + stones[i], stones, target));

    }


};