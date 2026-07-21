class Solution {
public:
    int cntones(int n) {
        int res = 0;
        while (n) {
            n &= n - 1;
            res++;
        }
        return res;
    }

    vector<int> countBits(int n) {
        vector<int> res;


        for (int i = 0; i <= n; i++) {
            res.push_back(cntones(i));
        }

        return res;
    }
};
