class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l = 0, r = 1;
        int res = 1, prev = -1;
        while (r < arr.size()) {
            if (arr[r - 1] > arr[r] and prev != 1) {
                res = max(res, r - l + 1);
                r += 1;
                prev = 1;
            } else if (arr[r - 1] < arr[r] and prev != 0) {
                res = max(res, r - l + 1);
                r += 1;
                prev = 0;
            } else {
                if (arr[r - 1] == arr[r]) r = r + 1;
                l = r - 1;
                prev = -1;
            }
        }

        return res;
    }
};