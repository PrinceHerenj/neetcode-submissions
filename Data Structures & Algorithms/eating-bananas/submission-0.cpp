class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1, r = piles[piles.size() - 1];
        int res = r;
        while (l <= r) {
            int k = l + (r - l) / 2;
            if (sumByK(piles, k) <= h) {
                res = k;
                r = k - 1;
            }
            else l = k + 1;
        }

        return res;
    }

    long long sumByK(vector<int>& piles, int k) {
        long long res = 0;
        for (auto p: piles) {
            res += ceil((double)p / k);
        }
        return res;
    }
};
