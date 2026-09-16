class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int l = 0;
        int r = 1;
        int res = -1;
        while (r < prices.size()) {
            if (prices[r] < prices[l]) l = r;
            res = max(res, prices[r] - prices[l]);
            r++;
        }
        return res;
    }
};
