class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res = {0};
        int msb = 1;
        for (int i = 1; i <= n; i++) {
            if (i == 2 * msb) msb = i;
            res.push_back(1 + res[i - msb]);
        }
        return res;
    }
};
