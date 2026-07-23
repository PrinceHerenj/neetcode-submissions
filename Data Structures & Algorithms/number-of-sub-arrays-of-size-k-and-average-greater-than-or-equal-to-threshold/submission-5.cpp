class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        vector<int> prefixSum(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++) {
            prefixSum[i + 1] = arr[i] + prefixSum[i];
        }

        int res = 0;
        int l = 0;
        for (int r = k - 1; r < arr.size(); r++) {
            int sum = prefixSum[r + 1] - prefixSum[l];
            if (sum >= threshold * k) res++;
            l++;
        }
        return res;
    }
};