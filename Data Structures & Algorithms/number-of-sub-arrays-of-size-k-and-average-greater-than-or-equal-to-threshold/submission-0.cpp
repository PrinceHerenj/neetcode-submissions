class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l = 0;
        int res = 0;
        for (int r = k - 1; r < arr.size(); r++) {
            if (r - l + 1 > k) l++;
            int sum = 0;
            for (int i = l; i <= r; i++) {
                sum += arr[i];
            }
            sum /= k;
            if (sum >= threshold) res++;
        }
        return res;
    }
};